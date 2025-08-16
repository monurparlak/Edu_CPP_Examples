/*
Question #8
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: A

Reason:
Step-by-step:

1. `B b; g(b);`
   - `g` takes its parameter by value: `void g(A a)`.
   - Passing `b` slices the `B` part; only the `A` subobject is copied.

2. `a.f();`
   - `f()` is virtual, but `a` is an `A` object due to slicing.
   - Virtual dispatch calls `A::f()` → prints "A".

3. Polymorphism only works via reference or pointer.
   - If `g(A &a)` or `g(A *a)` were used, `B::f()` would be called.

Concatenate (Final Result): "A"

If Wrong:
- If you answered "B": incorrect, slicing occurs because `g` takes by value.
- If you answered "AB": wrong, only the `A` subobject exists in `g`.
- If you answered "compile error": code compiles fine.

Reference:
- C++23 §11.9.2 — Object slicing and copy initialization
- C++23 §11.3.1 — Virtual function dispatch rules
*/
  
/* Actual Program Code: */

#include <iostream>

class A {
public:
  virtual void f() { std::cout << "A"; }
};

class B : public A {
public:
  void f() { std::cout << "B"; }
};

void g(A a) { a.f(); }

int main() {
  B b;
  g(b);
}
