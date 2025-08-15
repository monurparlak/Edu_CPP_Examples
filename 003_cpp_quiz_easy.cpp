/*
Question #3
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 1

Reason:
- The literal -2.5 is of type double.
- Overload resolution will try standard conversions for both candidates.
- Converting double to int is a standard floating-integral conversion.
- Converting double to unsigned is also a standard conversion but may
  involve modulo wrap for negatives, which is less desirable in ranking.
- Both are standard conversions, but the signed int version is preferred.
- So f(int) is chosen → prints 1.

If Wrong:
Explicitly cast to unsigned to call the other overload:
    f(static_cast<unsigned>(-2.5)); // would print 2

Reference:
C++23 §12.2.4.2 — Overload resolution and conversion ranking
*/

#include <iostream>

void f(int)      { std::cout << 1; }
void f(unsigned) { std::cout << 2; }

int main() {
    f(-2.5); // calls f(int) → prints 1
}
