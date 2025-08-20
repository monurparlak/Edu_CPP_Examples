/*
Question #26
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
❌ Output: Undefined (runtime error)

Reason:
- `i = 42` and `j = 1`.
- `--j` decrements `j` before use, so `j` becomes 0.
- The expression `i / --j` evaluates to `42 / 0`.
- Division by zero for integers is **undefined behavior** in C++23.
- The program may crash, throw an exception, or produce an arbitrary result.

If Wrong:
To avoid undefined behavior, ensure the divisor is non-zero:

    int i = 42;
    int j = 1;
    if (--j != 0) std::cout << i / j;
    else std::cout << "Division by zero!";

Reference:
C++23 §7.8.6/3 — Integer division by zero is undefined behavior
*/

#include <iostream>

int main() {
  int i = 42;
  int j = 1;
  std::cout << i / --j;
}
