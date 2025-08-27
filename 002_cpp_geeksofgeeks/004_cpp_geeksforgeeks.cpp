/*
Question #4
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find the ASCII Value of a Character.

My Answer:
✅ Output: The ASCII value of A is 65

Reason:
- Assign a character to a variable.
- Convert the character to int to get its ASCII value.
- Print the value using cout.

If Wrong:
Ensure the character is correctly assigned and converted to int for output.
*/

#include <iostream>
using namespace std;

int main() {
    char ch = 'A';

    cout << "The ASCII value of " << ch << " is " << int(ch) << endl;
    return 0;
}
