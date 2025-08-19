/*
Question #25
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
❌ Output: Undefined behavior

Reason:
- `i` is initialized to `std::numeric_limits<int>::max()`.
- `++i` increments `i`, which causes **signed integer overflow**.
- In C++23, signed integer overflow is **undefined behavior**.
- The program may produce any result, crash, or behave unpredictably.

If Wrong:
To safely handle integer overflow, use `unsigned int` or check before increment:

    unsigned int i = std::numeric_limits<unsigned int>::max();
    std::cout << ++i; // Well-defined (wraps around)

Reference:
C++23 §6.9.3/2 — Signed integer overflow is undefined behavior
*/

#include <iostream>
#include <limits>

int main() {
  int i = std::numeric_limits<int>::max();
  std::cout << ++i;
}
