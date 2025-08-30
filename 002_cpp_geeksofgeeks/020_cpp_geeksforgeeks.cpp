/*
Question #20
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find the GCD of Two Numbers.

My Answer:
✅ Output: GCD: 3

Reason:
- Start with the minimum of the two numbers.
- Decrease until a number divides both a and b.
- Return that number as the GCD.

If Wrong:
Ensure the loop checks all divisors from min(a,b) down to 1.
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0)
            break;
        result--;
    }
    return result;
}

int main() {
    int a = 54, b = 33;
    cout << "GCD: " << gcd(a, b) << endl;
    return 0;
}
