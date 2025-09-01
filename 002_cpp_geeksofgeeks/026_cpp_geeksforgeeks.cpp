/*
Question #26
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check if a Given String is Palindrome.

My Answer:
✅ Output: Yes

Reason:
- Compare characters from start and end moving towards center.
- If any mismatch, return "No".
- If all match, return "Yes".

If Wrong:
Ensure the loop runs only half the string length and compares symmetric chars.
*/

#include <iostream>
using namespace std;

string isPalindrome(string S) {
    for (int i = 0; i < S.length()/2; i++)
        if (S[i] != S[S.length()-i-1]) return "No";
    return "Yes";
}

int main() {
    string S = "GeekeeG";
    cout << isPalindrome(S) << endl;
    return 0;
}
