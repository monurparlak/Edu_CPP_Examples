/*
Question #16
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: abAB

Reason:
- `B b;` is created. Construction order:
  1. Member `A a` is constructed first → prints 'a'
  2. `B` constructor runs → prints 'b'
- Object goes out of scope at the end of `main()`. Destruction order:
  1. `B` destructor runs → prints 'B'
  2. Member `A a` is destroyed → prints 'A'
- Total output: 'a' 'b' 'B' 'A' → abAB

If Wrong:
Construction order for members is **in declaration order** inside the class.
No fix needed.

Reference:
C++23 §11.9 — Constructor and destructor call order for members
*/

#include <iostream>

class A {
public:
  A() { std::cout << 'a'; }
  ~A() { std::cout << 'A'; }
};

class B {
public:
  B() { std::cout << 'b'; }
  ~B() { std::cout << 'B'; }
  A a;
};

int main() { B b; }
