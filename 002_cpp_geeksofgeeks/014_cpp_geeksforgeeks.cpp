/*
Question #14
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find Factorial of a Number Using Loops.

My Answer:
✅ Output: 120

Reason:
- Initialize fact = 1.
- Multiply fact by n while decrementing n until n > 1.
- Return and print the result.

If Wrong:
Ensure loop decrements correctly and multiplication accumulates properly.
*/

#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    while (n > 1) {
        fact *= n;
        n--;
    }
    return fact;
}

int main() {
    int num = 5;
    cout << factorial(num) << endl;
    return 0;
}
