/*
Question #21
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find LCM of Two Numbers.

My Answer:
✅ Output: LCM : 312

Reason:
- Use formula LCM(a,b) = (a / GCD(a,b)) * b.
- GCD found recursively using Euclidean algorithm.
- Multiply a/GCD by b to get LCM.

If Wrong:
Ensure integer division is correct to avoid overflow and rounding errors.
*/

#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int a = 24, b = 13;
    cout << "LCM : " << lcm(a, b);
    return 0;
}
