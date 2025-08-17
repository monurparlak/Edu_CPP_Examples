/*
Question #12
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 0

Reason:
- `static int a;` is a local static variable.
- In C++23, all static variables are zero-initialized if no initializer is given.
- Therefore, `a` is initialized to 0 before the first use.
- `std::cout << a;` prints 0.

If Wrong:
Non-static local variables would be uninitialized, causing undefined behavior:

    int main() {
        int a;        // uninitialized
        std::cout << a; // undefined behavior
    }

Reference:
C++23 §6.7.4/4 — Static storage duration variables are zero-initialized
*/

#include <iostream>

int main() {
  static int a;
  std::cout << a;
}
