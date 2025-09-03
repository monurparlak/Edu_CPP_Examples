/*
Question #133
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: ABCD a b c d

Reason:
- Class hierarchy:
  - D : B, C
  - B, C : virtual A
- Virtual base classes are **constructed only once**, before non-virtual bases.
- Step by step:

1) `D d1;` → default constructor:
   - Construct virtual base A → prints "A"
   - Construct B → prints "B"
   - Construct C → prints "C"
   - Construct D → prints "D"
   - So d1 → prints "ABCD"

2) `D d2(d1);` → copy constructor:
   - Virtual base A → copy-constructed from d1.A → prints "a"
   - B → copy-constructed from d1.B → prints "b"
   - C → copy-constructed from d1.C → prints "c"
   - D → copy constructor body → prints "d"
   - So d2 → prints "abcd"

- Therefore, full output: **ABCDabcd**

If Wrong:
- Many expect multiple A prints; virtual inheritance ensures **A is constructed only once**.
- Copy constructor of D triggers copy of virtual base first, then non-virtual bases.

Reference:
C++23 §15.6 — Virtual base class construction and copy behavior
*/

#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A"; }
    A(const A&) { cout << "a"; }
};

class B : public virtual A {
public:
    B() { cout << "B"; }
    B(const B&) { cout << "b"; }
};

class C : public virtual A {
public:
    C() { cout << "C"; }
    C(const C&) { cout << "c"; }
};

class D : B, C {
public:
    D() { cout << "D"; }
    D(const D&) { cout << "d"; }
};

int main() {
    D d1;       // prints ABCD
    D d2(d1);   // prints abcd
    // Output: ABCDabcd
}
