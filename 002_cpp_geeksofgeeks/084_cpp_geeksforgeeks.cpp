/*
Question #84
Source: CPP GeeksforGeeks

Question:
Write a C++ program to reverse a string by printing it from last character to first.

My Answer:
✅ Output for input "GeeksforGeeks":

skeeGrofskeeG

Reason:
- Iterate over the string from the last index to the first index.
- Print each character in this reverse order.
- No additional storage is used; reversal is printed directly.

If Wrong:
- Ensure the loop starts from str.length() - 1 and decrements to 0 inclusive.
- Avoid going out of bounds by checking the loop condition.
*/

#include <iostream>
using namespace std;

void reverse(string str) {
    for (int i = str.length() - 1; i >= 0; i--)
        cout << str[i];
}

int main(void) {
    string str = "GeeksforGeeks";
    reverse(str);
    return 0;
}
