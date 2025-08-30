/*
Question #16
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Whether a Number is Prime or Not.

My Answer:
✅ Output:
 false
 true

Reason:
- Numbers ≤1 are not prime.
- Loop from 2 to n-1; if divisible, return false.
- Otherwise, return true.

If Wrong:
Check loop range and the base condition for n ≤ 1.
*/

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    isPrime(21) ? cout << " false\n" : cout << " true\n";
    isPrime(17) ? cout << " true\n" : cout << " false\n";
    return 0;
}
