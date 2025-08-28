/*
Question #7
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find the Length of a String Without Using strlen().

My Answer:
✅ Output: The length of the string is: 13

Reason:
- Iterate through each character until the null terminator '\0'.
- Increment a counter for each character.
- Print the final length.

If Wrong:
Ensure the loop stops at '\0' and counts all characters correctly.
*/

#include <iostream>
using namespace std;

int main() {
    string str = "GeeksforGeeks";
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++)
        length++;

    cout << "The length of the string is: " << length << endl;
    return 0;
}
