/*
Question #39
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Whether a Given String is a Palindrome Using Recursion.

My Answer:
✅ Output: Yes

Reason:
- Base case: if start index == end index, it's palindrome.
- Compare first and last characters; if unequal, return false.
- Recursive call: check inner substring.
- Works for any null-terminated char array.

If Wrong:
Ensure string is properly null-terminated.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalRec(char str[], int s, int n) {
    if (s >= n) return true;        // base case
    if (str[s] != str[n]) return false; // mismatch
    return isPalRec(str, s + 1, n - 1);
}

bool isPalindrome(char str[]) {
    int n = strlen(str);
    if (n == 0) return true;
    return isPalRec(str, 0, n - 1);
}

int main() {
    char str[] = "GeeKeeG";
    if (isPalindrome(str))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
