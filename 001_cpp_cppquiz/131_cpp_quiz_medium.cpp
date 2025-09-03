/*
Question #131
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: id

Reason:
- Class C has two constructors:
  1) `explicit C(int)` → cannot be used for implicit conversions
  2) `C(double)` → non-explicit, allows implicit conversions
- Step by step:

1) `C c1(7);`
   - Direct initialization with int
   - `explicit C(int)` is **called** → prints "i"

2) `C c2 = 7;`
   - Copy-initialization (assignment-style)
   - Explicit constructors **cannot** be used here
   - `C(double)` is selected with implicit conversion int → double → prints "d"

- Therefore, output: **id**

If Wrong:
- Some may expect "ii"; remember **explicit constructors are ignored in copy-initialization**.

Reference:
C++23 §12.3.1 — Explicit constructors and copy-initialization rules
*/

#include <iostream>
using namespace std;

class C {
public:
    explicit C(int) { cout << "i"; }
    C(double) { cout << "d"; }
};

int main() {
    C c1(7);   // prints "i"
    C c2 = 7;  // prints "d"
    // Output: id
}
