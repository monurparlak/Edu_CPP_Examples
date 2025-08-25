/*
Question #37
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 01

Reason:
Step-by-step:

1. `int a = 0;`
   - Simple integer variable `a` initialized to 0.

2. `decltype(a) b = a;`
   - `decltype(a)` yields `int` because `a` is a simple variable (not an expression in parentheses).
   - `b` is a separate integer, not a reference.

3. `b++;`
   - Increments `b`, not `a`.
   - `b` becomes 1, `a` remains 0.

4. `std::cout << a << b;`
   - Prints `"0"` for `a` and `"1"` for `b`.
   - Final output: `"01"`.

If Wrong:
If you expected `"11"`, you might have confused this with `decltype((a))` which yields `int&`.

Reference:
C++23 §11.4.5.2 — `decltype` rules for variable names vs lvalue expressions
*/

#include <iostream>

int main() {
  int a = 0;
  decltype(a) b = a;
  b++;
  std::cout << a << b;
}
