/*
Question #18
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: A

Reason:
- `B` inherits from `A` and has a **private** override of `f()`.
- `g(A &a)` calls `a.f()`. Virtual dispatch uses the **most derived accessible**
  function.
- `B::f()` is private and not accessible from `g`, so `A::f()` is called instead.
- Therefore, the program prints 'A'.

If Wrong:
Making `B::f()` public would override `A::f()` in the call via `g(b)`:

    class B : public A {
    public:
      void f() { std::cout << "B"; }
    };

Output would then be 'B'.

Reference:
C++23 §11.7 — Access rules affect virtual function dispatch
*/

#include <iostream>

class A {
public:
  virtual void f() { std::cout << "A"; }
};

class B : public A {
private:
  void f() { std::cout << "B"; }
};

void g(A &a) { a.f(); }

int main() {
  B b;
  g(b);
}
