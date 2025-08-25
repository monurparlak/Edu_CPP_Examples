/*
Question #7
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: A

Reason:
Step-by-step:

1. `B b; g(b);`
   - `g` takes its parameter by reference: `void g(A &a)`.
   - `b` is a `B` object, but `g` sees it as an `A&`.

2. `a.f();`
   - `f()` in `A` is **non-virtual**.
   - Non-virtual functions are resolved **statically** based on the type
     of the reference (`A&`), not the dynamic type (`B`).

3. Result:
   - `A::f()` is called → prints "A".

Concatenate (Final Result): "A"

If Wrong:
- If you answered "B": incorrect, `f()` is non-virtual; dynamic type is ignored.
- If you answered "AB" or "BA": wrong, only `A::f()` executes.
- If you answered "compile error": code compiles fine.

Reference:
- C++23 §13.4 — Non-virtual member function calls
- C++23 §11.3 — Static vs. dynamic dispatch rules
*/
  
/* Actual Program Code: */

#include <iostream>

class A {
public:
  void f() { std::cout << "A"; }
};

class B : public A {
public:
  void f() { std::cout << "B"; }
};

void g(A &a) { a.f(); }

int main() {
  B b;
  g(b);
}
