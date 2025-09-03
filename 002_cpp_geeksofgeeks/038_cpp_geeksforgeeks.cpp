/*
Question #38
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Reverse a String Using Recursion.

My Answer:
✅ Output: skeeGrofskeeG

Reason:
- Base case: if start index >= end index, stop recursion.
- Swap first and last characters.
- Recursive call on inner substring.
- Works in-place using string reference.

If Wrong:
Check that indices passed are correct: 0 and str.length() - 1.
*/

#include <iostream>
using namespace std;

void reverse_str(string& s, int n, int i) {
    if (i >= n) return;       // base case
    swap(s[i], s[n]);
    reverse_str(s, n - 1, i + 1); // recursive call
}

int main() {
    string str = "GeeksforGeeks";
    reverse_str(str, str.length() - 1, 0);
    cout << str << endl;
    return 0;
}
