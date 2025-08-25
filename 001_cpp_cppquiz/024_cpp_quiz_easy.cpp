/*
Question #24
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 0

Reason:
- `i` is initialized to `std::numeric_limits<unsigned int>::max()`.
- `++i` increments `i`. Unsigned integer arithmetic in C++ wraps modulo 2^n.
- For `unsigned int`, `max + 1` wraps to 0.
- Therefore, the program prints 0.

If Wrong:
Unsigned integer overflow is well-defined and wraps around. No fix needed.

Reference:
C++23 §6.9.3/2 — Unsigned integer arithmetic wraps modulo 2^n
*/

#include <iostream>
#include <limits>

int main() {
  unsigned int i = std::numeric_limits<unsigned int>::max();
  std::cout << ++i;
}
