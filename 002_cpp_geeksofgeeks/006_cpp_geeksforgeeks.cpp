/*
Question #6
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Whether a Character is an Alphabet or Not.

My Answer:
✅ Output: a is an alphabet.

Reason:
- Use the isalpha() function to check if the character is a letter.
- If true, print that it's an alphabet; otherwise, print it's not.

If Wrong:
Ensure the character is correctly assigned and isalpha() is used properly.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch = 'a';

    if (isalpha(ch))
        cout << ch << " is an alphabet." << endl;
    else
        cout << ch << " is not an alphabet." << endl;

    return 0;
}
