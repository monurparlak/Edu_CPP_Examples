/*
Question #11
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 0

Reason:
- `int a;` is a global variable, so it has static storage duration.
- In C++23, all variables with static storage duration are zero-initialized
  before any other initialization.
- Therefore, `a` is automatically set to 0.
- `std::cout << a;` prints 0.

If Wrong:
If `a` were a local variable, it would not be zero-initialized.
Using it uninitialized would lead to undefined behavior:

    int main() {
        int a;              // uninitialized local variable
        std::cout << a;     // undefined behavior
    }

Reference:
C++23 §6.7.4/4 — Objects with static storage duration are zero-initialized
*/

#include <iostream>

int a;

int main() {
    std::cout << a;
}
