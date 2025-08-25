/*
Question #28
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: AABCBC

Reason:
- `A a[2];` creates two objects:
  - First element: default constructor → prints 'A'
  - Second element: default constructor → prints 'A'
- Range-based for loop: `for (auto x : a)` copies each element into `x`.
  - Copy constructor (`A(const A&)`) runs → prints 'B'
  - `x.f()` calls virtual function on copy → prints 'C'
- Step by step:
  - First iteration: B + C → 'BC'
  - Second iteration: B + C → 'BC'
- Total output: AA (creation) + BCBC (loop) = AABCBC

If Wrong:
To avoid copying, use references:

    for (auto &x : a) {
        x.f();
    }

This prints only 'C' for each element during the loop, without 'B' from copies:
Output: AACC

Reference:
C++23 §11.6.4 — Range-based for loop mechanics
*/

#include <iostream>

struct A {
  A() { std::cout << "A"; }
  A(const A &a) { std::cout << "B"; }
  virtual void f() { std::cout << "C"; }
};

int main() {
  A a[2];
  for (auto x : a) {
    x.f();
  }
}
