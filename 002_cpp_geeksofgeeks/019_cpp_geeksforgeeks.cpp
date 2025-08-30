/*
Question #19
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find the Nth Term of the Fibonacci Series.

My Answer:
✅ Output: 233

Reason:
- Initialize first=0 and second=1.
- Iterate from 2 to n, updating ans=first+second.
- Shift first and second, then return ans.

If Wrong:
Ensure the loop starts from i=2 and handles n=0 correctly.
*/

#include <iostream>
using namespace std;

int fib(int n) {
    int first = 0, second = 1, ans;
    if (n == 0) return first;

    for (int i = 2; i <= n; i++) {
        ans = first + second;
        first = second;
        second = ans;
    }
    return ans;
}

int main() {
    int n = 13;
    cout << fib(n) << endl;
    return 0;
}
