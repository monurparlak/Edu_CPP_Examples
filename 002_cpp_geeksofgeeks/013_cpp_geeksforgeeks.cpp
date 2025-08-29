/*
Question #13
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find the Sum of First n Natural Numbers.

My Answer:
✅ Output: 28

Reason:
- Initialize sum = 0.
- Loop i from 1 to n, adding i to sum.
- Return and print sum.

If Wrong:
Ensure loop runs up to n and sum is correctly accumulated.
*/

#include <iostream>
using namespace std;

int findSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    return sum;
}

int main() {
    int n = 7;
    cout << findSum(n) << endl;
    return 0;
}
