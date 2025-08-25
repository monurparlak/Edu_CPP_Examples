/*
Question #13
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: a c b B C A

Reason:
- Global `A a;` is constructed before `main()` → prints 'a'
- `C c;` local in `main()` → constructor prints 'c'
- `B b;` local in `main()` → constructor prints 'b'
- At program exit, destructors run in reverse order:
  1. `B b` → prints 'B'
  2. `C c` → prints 'C'
  3. Global `A a` → prints 'A'
- Total output: a c b B C A

If Wrong:
Remember:
- Global objects are initialized before `main()`
- Local objects destroyed in reverse order of creation

Reference:
C++23 §11.9 — Object destruction order
C++23 §6.7.4 — Initialization of globals
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

int main() {
  C c;
  B b;
}
