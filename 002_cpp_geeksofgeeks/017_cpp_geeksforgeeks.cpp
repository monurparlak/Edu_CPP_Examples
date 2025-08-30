/*
Question #17
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Whether a Number is Palindrome or Not.

My Answer:
✅ Output: Yes

Reason:
- Reverse the number using a loop.
- Compare the reversed number with the original.
- If equal, print "Yes"; otherwise, print "No".

If Wrong:
Ensure the reversal logic is correct and comparison is made with original number.
*/

#include <iostream>
using namespace std;

bool checkPalindrome(int n) {
    int ans = 0, temp = n;
    while (temp != 0) {
        ans = (ans * 10) + (temp % 10);
        temp /= 10;
    }
    return (ans == n);
}

int main() {
    int n = 12321;
    if (checkPalindrome(n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
