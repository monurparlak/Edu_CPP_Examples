/*
Question #115
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: d

Reason:
- Overloads are:
    f(int)    → prints "i"
    f(double) → prints "d"
    f(float)  → prints "f"
- The literal 1.0 is a double by default in C++.
- So the best match is f(double) with no conversion.
- Therefore, f(double) is called, printing "d".

If Wrong:
If you expected "f", that would require writing 1.0f (a float literal).
If you expected "i", that would require an explicit cast or integer literal.

Reference:
C++23 §5.13.4 — Floating-point literals (default type is double)
*/

#include <iostream>
using namespace std;

void f(int)    { cout << "i"; }
void f(double) { cout << "d"; }
void f(float)  { cout << "f"; }

int main() {
    f(1.0); // calls f(double), prints "d"
    return 0;
}
