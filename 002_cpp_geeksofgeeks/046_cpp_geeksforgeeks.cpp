/*
Question #46
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Equality of Two Numbers Without Using Arithmetic or Comparison Operators.

My Answer:
✅ Output: Equal

Reason:
- Use XOR (^) operator: a^b == 0 only if a == b.
- If XOR is non-zero, numbers are different; else they are equal.

If Wrong:
Ensure proper use of bitwise XOR instead of logical operators.
*/

#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 10;
    if (a ^ b)
        cout << "Not-Equal";
    else
        cout << "Equal";
    return 0;
}
