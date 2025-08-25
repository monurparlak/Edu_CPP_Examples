/*
Question #17
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: abBA

Reason:
- `B b;` is created. Construction order:
  1. Base class `A` constructor → prints 'a'
  2. Derived class `B` constructor → prints 'b'
- Object goes out of scope at the end of `main()`. Destruction order:
  1. Derived class `B` destructor → prints 'B'
  2. Base class `A` destructor → prints 'A'
- Total output: 'a' 'b' 'B' 'A' → abBA

If Wrong:
Construction always starts from base classes, destruction happens in reverse.
No fix needed.

Reference:
C++23 §11.9 — Constructor and destructor call order
*/

#include <iostream>

class A {
public:
  A() { std::cout << 'a'; }
  ~A() { std::cout << 'A'; }
};

class B : public A {
public:
  B() { std::cout << 'b'; }
  ~B() { std::cout << 'B'; }
};

int main() { B b; }
