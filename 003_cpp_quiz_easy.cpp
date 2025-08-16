/*
Question #3
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 1

Reason:
Step-by-step:

1. `f(-2.5);`
   - The argument is a double literal (-2.5).
   - Candidate functions:
     - `f(int)` requires a standard conversion from double → int.
     - `f(unsigned)` requires double → unsigned conversion.

2. Overload resolution:
   - Both conversions are standard conversions.
   - Signed int conversion is preferred over unsigned for negative numbers.

3. So `f(int)` is called → prints "1".

Concatenate (Final Result): "1"

If Wrong:
- If you answered "2": you assumed unsigned is preferred, but signed int is
  chosen because the value is negative.
- If you answered "compile error": both overloads are valid, no error occurs.

Reference:
- C++23 §13.3.3 — Overload resolution and ranking of conversions
*/
  
/* Actual Program Code: */

#include <iostream>

void f(int) { std::cout << 1; }
void f(unsigned) { std::cout << 2; }

int main() {
  f(-2.5);
}
