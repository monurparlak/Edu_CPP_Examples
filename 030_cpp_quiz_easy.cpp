/*
Question #30
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: (no output)

Reason:
- `X x();` looks like a variable definition but is actually a function declaration.
- This is the "Most Vexing Parse" in C++.
- The compiler interprets it as a declaration of a function `x` that returns `X`.
- Therefore, the constructor `X()` is never called, and nothing is printed.

If Wrong:
To actually create an object of type `X`, remove the parentheses or use
uniform initialization:

    int main() { X x; }       // Prints: X
    int main() { X x{}; }     // Prints: X

Reference:
C++23 §11.4/1 — Most vexing parse rules for declarations
*/

#include <iostream>
struct X {
  X() { std::cout << "X"; }
};

int main() { X x(); }
