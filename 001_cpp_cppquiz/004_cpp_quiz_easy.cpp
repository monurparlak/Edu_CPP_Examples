/*
Question #4
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 21

Reason:
Step-by-step:

1. `f(2.5);`
   - 2.5 is a double literal by default.
   - Candidate functions:
     - `f(float)` requires narrowing conversion (double → float).
     - `f(double)` is an exact match.
   - Exact match is preferred → `f(double)` is called → prints "2".

2. `f(2.5f);`
   - 2.5f is a float literal.
   - Candidate functions:
     - `f(float)` exact match → prints "1".
     - `f(double)` requires float → double conversion.
   - Exact match is preferred → `f(float)` is called → prints "1".

Concatenate (Final Result): "21"

If Wrong:
- If you answered "12": you reversed the literal types; double is first call,
  float is second.
- If you answered "22" or "11": incorrect, overload resolution prefers exact matches.
- If you answered "compile error": all overloads are valid.

Reference:
- C++23 §13.3.3 — Overload resolution and ranking of conversions
*/
  
/* Actual Program Code: */

#include <iostream>

void f(float) { std::cout << 1; }
void f(double) { std::cout << 2; }

int main() {
  f(2.5);
  f(2.5f);
}
