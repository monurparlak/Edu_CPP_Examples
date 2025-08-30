/*
Question #112
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 14 26

Reason:
- Class A has:
  - Default constructor → prints 1
  - Copy constructor → prints 2
  - Move constructor → prints 3
- Class B has:
  - Member a of type A
  - Default constructor → prints 4
  - Copy constructor → prints 5
  - Move constructor → prints 6
- Member initialization order: **members are initialized in declaration order**, not constructor initializer order.
- Step by step:

1) B b1;
- Default constructor of B called
- Member a default constructed → prints 1
- Then body of B() prints 4
- So b1 → prints "14"

2) B b2 = std::move(b1);
- Move constructor B(B&& b) called
- Member a initialized with b.a → calls **copy constructor** of A (because a(b.a) is copy, not move) → prints 2
- Then body of B(B&&) prints 6
- So b2 → prints "26"

Final output: **14 26**

If Wrong:
- If you expected A's move constructor (3) to be called in b2 initialization,
  note that `a(b.a)` explicitly copies b.a; to move, write `a(std::move(b.a))`.

Reference:
C++23 §12.6 — Constructor initialization rules, member initialization order
*/

#include <iostream>
#include <utility>
using namespace std;

struct A {
    A()       { cout << "1"; }
    A(const A&) { cout << "2"; }
    A(A&&)    { cout << "3"; }
};

struct B {
    A a;
    B() { cout << "4"; }
    B(const B& b) : a(b.a) { cout << "5"; }
    B(B&& b) : a(b.a) { cout << "6"; }
};

int main() {
    B b1;             // prints 14
    B b2 = move(b1);  // prints 26
    return 0;         // Output: 14 26
}
