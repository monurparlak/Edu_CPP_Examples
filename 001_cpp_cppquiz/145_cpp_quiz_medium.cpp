/*
Question #145
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 13

Reason:
- Struct E has:
  - Default constructor → prints "1"
  - Copy constructor → prints "2"
  - Destructor → prints "3"
- Function f() returns `E()` by value.
- C++ compilers perform **mandatory copy elision** (C++17 onward):
  - No temporary copy is made for the return value; E() is constructed directly in the caller context.
  - Therefore, only the constructor for E() is called → prints "1"
- Temporary returned by f() is destroyed at the end of full-expression in main → prints "3"
- No copy constructor is called because of mandatory elision.

If Wrong:
- If you expected "123", note that C++17 and later mandate copy elision for prvalues, so
  the copy constructor is not invoked.

Reference:
C++23 §12.8 — Copy elision and temporary materialization
*/

#include <iostream>
using namespace std;

struct E {
    E()       { cout << "1"; }
    E(const E&) { cout << "2"; }
    ~E()      { cout << "3"; }
};

E f() {
    return E(); // prvalue returned, copy elided
}

int main() {
    f();       // constructs E() → "1", destroyed at end → "3"
    return 0;  // Output: 13
}
