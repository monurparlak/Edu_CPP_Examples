/*
Question #29
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 12

Reason:
- `B b;` is created. First, the base class `A` constructor runs.
- `A()` constructor calls `foo();`. During construction, virtual dispatch
  does not reach the derived class. So `A::foo()` is called → prints 1.
- `b.bar();` calls `foo();` on the fully constructed object. Virtual dispatch
  selects `B::foo()` → prints 2.
- Therefore, the output is 12.

If Wrong:
To call the derived class's `foo()` during construction (which C++ forbids),
call it after the object is fully constructed:

    struct A {
      A() {}
      virtual void foo() { std::cout << "1"; }
      void bar() { foo(); }
    };

    struct B : public A {
      void foo() override { std::cout << "2"; }
    };

    int main() {
      B b;
      b.foo(); // Prints: 2
      b.bar(); // Prints: 2
    }

Reference:
C++23 §11.7.3/6 — Virtual function calls during construction and destruction
*/

#include <iostream>

struct A {
  A() { foo(); }
  virtual ~A() { foo(); }
  virtual void foo() { std::cout << "1"; }
  void bar() { foo(); }
};

struct B : public A {
  virtual void foo() { std::cout << "2"; }
};

int main() {
  B b;
  b.bar();
}
