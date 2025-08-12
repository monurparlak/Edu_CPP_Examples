/*
Question #4
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 21

Reason:
- The literal 2.5 is of type double.
- f(double) matches exactly, so it is chosen → prints 2.
- The literal 2.5f is of type float.
- f(float) matches exactly, so it is chosen → prints 1.
- Combined output: 21.

If Wrong:
If both calls should go to f(float), cast explicitly:
    f(static_cast<float>(2.5));
    f(2.5f);

Reference:
C++23 §12.2.4.2 — Overload resolution and exact match rules
*/

#include <iostream>

void f(float)  { std::cout << 1; }
void f(double) { std::cout << 2; }

int main() {
    f(2.5);  // calls f(double) → prints 2
    f(2.5f); // calls f(float)  → prints 1
}
