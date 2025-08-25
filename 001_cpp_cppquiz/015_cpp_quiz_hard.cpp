/*
Question #15
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: abcABabAB

Reason:
- Global `x = 0`.
- `foo()` creates a **static B b**. Static objects are initialized once.
- First call to `foo()`:
  1. `B` constructor starts → prints 'b'
  2. Member `A a` constructor runs:
     - prints 'a'
     - `x++ == 0` → true → throws `std::exception()`
- Exception is caught in `main()` → prints 'c'
- `B` partially constructed during throw:
  - Only fully constructed subobjects are destroyed:
    - `B` not fully constructed, member `a` partially constructed → destructor
      of `a` runs → prints 'A'
- Second call to `foo()`:
  - Static `b` was not successfully initialized, so C++ attempts **reinitialization**.
  - Now `x = 1`, `A` constructor does not throw → prints 'a' (member)
  - `B` constructor completes → prints 'b'
- Program exits → static `b` destructor runs:
  - `B` destructor → prints 'B'
  - Member `a` destructor → prints 'A'
- Total output: ab c AB a b AB → ab c ABabAB

If Wrong:
Static local initialization is retried if initialization throws before completion.
This explains why `foo()` prints again after catching.

Reference:
C++23 §6.7.9 — Static local variable initialization and exceptions
*/

#include <iostream>
#include <exception>

int x = 0;

class A {
public:
  A() {
    std::cout << 'a';
    if (x++ == 0) {
      throw std::exception();
    }
  }
  ~A() { std::cout << 'A'; }
};

class B {
public:
  B() { std::cout << 'b'; }
  ~B() { std::cout << 'B'; }
  A a;
};

void foo() { static B b; }

int main() {
  try {
    foo();
  }
  catch (std::exception &) {
    std::cout << 'c';
    foo();
  }
}
