/* ================================================================================
HackerRank C++ Challenge: Username Validation Exception (*.cpp)
================================================================================

This C++ program demonstrates custom exception handling for username validation.
It defines a user-defined exception class BadLengthException, which stores the
length of a too-short username and allows reporting it via the what() method.

The function checkUsername checks the username rules:
- Must be at least 5 characters long.
- Must not contain "ww" consecutively.

If the username is too short, a BadLengthException is thrown.
If the username contains "ww", the function returns false (Invalid).

================================================================================
*/

#include <iostream>
#include <string>
#include <exception>
using namespace std;

class BadLengthException : public exception {
private:
    int length;
    string msg;
public:
    BadLengthException(int n) : length(n) {
        msg = to_string(n);
    }

    // std::exception::what() function overrided
    const char* what() const noexcept override {
        return msg.c_str();
    }
};


// Function to check username validity
bool checkUsername(string username) {
    int n = username.length();
    if (n < 5) {
        // Throw exception if username is too short
        throw BadLengthException(n);
    }

    // Check for consecutive 'w' characters
    for (int i = 0; i < n - 1; i++) {
        if (username[i] == 'w' && username[i + 1] == 'w') {
            return false; // Invalid username
        }
    }

    return true; // Username is valid
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        string username;
        cin >> username;

        try {
            bool isValid = checkUsername(username);
            if (isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        } 
        catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';
        }
    }

    return 0;
}

/* ================================================================================
Notes:
- The exception BadLengthException carries the length of the invalid username.
- Using try-catch, we handle both valid, invalid, and too-short usernames.
- The program prints:
    "Valid"   -> if username passes all checks
    "Invalid" -> if username contains "ww"
    "Too short: n" -> if username length < 5
================================================================================
*/

