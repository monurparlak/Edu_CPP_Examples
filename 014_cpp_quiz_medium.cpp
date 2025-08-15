/*
Question #14
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: abcCBA

Reason:
- Global `A a;` is constructed before `main()` → prints 'a'
- `B b;` is a local object in `main()` → constructor prints 'b'
- `foo()` creates a static `C c;` → first call constructs `c` → prints 'c'
- Program exits, destructors run in reverse order:
  1. Static `C c` → prints 'C'
  2. Local `B b` → prints 'B'
  3. Global `A a` → prints 'A'
- Total output: 'a' 'b' 'c' 'C' 'B' 'A' → abcCBA

If Wrong:
Remember: static locals initialized on first call, destructors run in reverse order
for all objects at program exit.

Reference:
C++23 §6.7.9 — Static local variables
C++23 §11.9 — Object destruction order
*/

#include <iostream>

class A {
public:
  A() { std::cout << "a"; }
  ~A() { std::cout << "A"; }
};

class B {
public:
  B() { std::cout << "b"; }
  ~B() { std::cout << "B"; }
};

class C {
public:
  C() { std::cout << "c"; }
  ~C() { std::cout << "C"; }
};

A a;

void foo() { static C c; }

int main() {
  B b;
  foo();
}
