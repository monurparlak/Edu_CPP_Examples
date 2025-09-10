/*
Question #148
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: unspecified / implementation-defined

Reason:
- `a` is declared as `volatile int a;`.
- Volatile tells the compiler that `a` can be modified outside program flow.
- Expression: `a + a`
  - The standard does **not define** the order of reads for the two operands.
  - Each read may yield a different value if `a` is changed externally (e.g., by hardware or another thread).
- Therefore, the program prints **unspecified value**. It is valid C++,
  but the output is **implementation-defined** if `a` is modified concurrently,
  or unspecified if only volatile semantics are considered.

If Wrong:
- Do not expect a fixed number; reading the same volatile object twice in one
  expression without sequence points does **not guarantee same value**.

Reference:
C++23 §7.6.2 — Volatile objects and value computation rules
*/

#include <iostream>
using namespace std;

volatile int a;

int main() {
    cout << (a + a); // unspecified / implementation-defined output
    return 0;
}
