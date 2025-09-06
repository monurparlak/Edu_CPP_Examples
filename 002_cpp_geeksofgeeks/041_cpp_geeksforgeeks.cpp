/*
Question #41
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Calculate Factorial of a Given Number Using Recursion.

My Answer:
✅ Output: Factorial of 15 is 1307674368000

Reason:
- Base case: factorial(0) = 1 and factorial(1) = 1.
- Recursive step: multiply n by factorial(n-1).
- Works for any non-negative integer.
- Uses unsigned long long to store large factorials.

If Wrong:
Check for negative input (not handled here) and integer overflow.
*/

#include <iostream>
using namespace std;

unsigned long long factorial(unsigned long long n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    unsigned long long num = 15;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
