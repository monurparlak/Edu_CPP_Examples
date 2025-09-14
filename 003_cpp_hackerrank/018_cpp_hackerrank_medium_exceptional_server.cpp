/* ================================================================================
HackerRank C++ Challenge: Server Exception Handling (*.cpp)
================================================================================

This is the complete C++ source code for handling exceptions in the Server class.
It demonstrates usage of try-catch blocks, memory allocation exception handling,
standard exceptions, and catch-all for non-standard exceptions.
It also maintains and prints the server load.

================================================================================
*/

#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Server class simulates computation with potential exceptions
class Server {
private:
    static int load; // Tracks number of compute requests
public:
    static int compute(long long A, long long B) {
        load += 1; // increment server load
        if (A < 0) {
            throw invalid_argument("A is negative"); // standard exception
        }

        vector<int> v(A, 0); // may throw std::bad_alloc

        int real = -1;
        if (B == 0) throw 0; // non-standard exception

        real = (A / B) * real;
        int ans = v.at(B); // may throw std::out_of_range
        return real + A - B * ans;
    }

    static int getLoad() {
        return load;
    }
};

// Initialize static member
int Server::load = 0;

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        long long A, B;
        cin >> A >> B;

        try {
            // Attempt computation
            int result = Server::compute(A, B);
            cout << result << endl;
        }
        catch (bad_alloc&) { 
            // Memory allocation failure
            cout << "Not enough memory" << endl;
        }
        catch (exception& e) { 
            // Any standard exception (e.g., invalid_argument, out_of_range)
            cout << "Exception: " << e.what() << endl;
        }
        catch (...) { 
            // Any non-standard exception
            cout << "Other Exception" << endl;
        }
    }

    // Print the total server load at the end
    cout << Server::getLoad() << endl;

    return 0;
}

/* ================================================================================
Notes:
- Server::compute may throw:
    * invalid_argument if A < 0
    * bad_alloc if vector allocation fails
    * out_of_range if accessing vector beyond bounds
    * any non-standard exception (e.g., integer)
- The main function reads T test cases and handles exceptions accordingly.
- Server::getLoad() prints the total number of compute calls.
================================================================================
*/

