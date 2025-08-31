/*
Question #22
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find Roots of a Quadratic Equation ax^2 + bx + c = 0.

My Answer:
✅ Output:
Roots are real and same 
-2

Reason:
- Calculate discriminant D = b^2 - 4ac.
- If D > 0: roots are real and different.
- If D == 0: roots are real and same.
- If D < 0: roots are complex.

If Wrong:
Ensure correct handling for D = 0 and D < 0 cases and type casting to double.
*/

#include <iostream>
#include <cmath>
using namespace std;

void findRoots(int a, int b, int c) {
    if (a == 0) { cout << "Invalid"; return; }
    int d = b*b - 4*a*c;
    double sqrt_val = sqrt(abs(d));
    if (d > 0) {
        cout << "Roots are real and different\n";
        cout << (-b + sqrt_val)/(2*a) << "\n" << (-b - sqrt_val)/(2*a);
    } else if (d == 0) {
        cout << "Roots are real and same\n";
        cout << -(double)b/(2*a);
    } else {
        cout << "Roots are complex\n";
        cout << -(double)b/(2*a) << " + i" << sqrt_val/(2*a) << "\n"
             << -(double)b/(2*a) << " - i" << sqrt_val/(2*a);
    }
}

int main() {
    int a = 1, b = 4, c = 4;
    findRoots(a, b, c);
    return 0;
}
