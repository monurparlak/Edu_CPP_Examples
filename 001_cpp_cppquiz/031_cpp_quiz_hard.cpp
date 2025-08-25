/*
Question #31
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: XYf

Reason:
- `X()` creates a temporary `X` object, so `X`’s constructor runs first → prints "X".
- The temporary `X` is passed to `Y`’s constructor by const reference:
  - `Y(const X&)` is called → prints "Y".
- `y.f()` is then called → prints "f".
- No extra spaces or newlines are inserted, so final output is `"XYf"`.

If Wrong:
A common mistake is to think this prints "Xf" due to the *most vexing parse*,
but in C++11 and later, `Y y(X());` is **not** a function declaration here
because it's in the `main` body with `X()` producing a prvalue.  
Most vexing parse would be an issue for older parsing rules when the syntax
is ambiguous, but here it is unambiguous.

Reference:
C++23 §6.8.1 [stmt.ambig] — disambiguation rules for function-style syntax
C++23 §11.6.4 — prvalue temporary materialization and constructor calls
*/

#include <iostream>

struct X {
  X() { std::cout << "X"; }
};

struct Y {
  Y(const X &x) { std::cout << "Y"; }
  void f() { std::cout << "f"; }
};

int main() {
  Y y(X());
  y.f();
}
