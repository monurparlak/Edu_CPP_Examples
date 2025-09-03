/*
Question #40
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Calculate Length of a String Using Recursion.

My Answer:
✅ Output: 13

Reason:
- Base case: if current character is '\0', return 0.
- Recursive step: return 1 + length of remaining string.
- Works for any null-terminated char array.
- No loops used.

If Wrong:
Make sure string is null-terminated.
*/

#include <iostream>
using namespace std;

int cal(char* str) {
    if (*str == '\0') return 0;
    return 1 + cal(str + 1);
}

int main() {
    char str[] = "GeeksforGeeks";
    cout << cal(str);
    return 0;
}
