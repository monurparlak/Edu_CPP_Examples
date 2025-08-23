/*
Question #41
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: B

Reason:
- In C++, the built-in subscript operator `operator[]` is defined as:
    a[b]  ≡  *(a + b)
- Addition is commutative for pointer arithmetic in this context:
    1["ABC"]  ≡  *(1 + "ABC")  ≡  *("ABC" + 1)
- `"ABC"` is a string literal of type `const char[4]` (with characters `'A'`, `'B'`, `'C'`, `'\0'`).
- `"ABC" + 1` points to the second character `'B'`.
- Dereferencing gives `'B'`.
- `std::cout` prints the character `'B'`.

If Wrong:
If you expect an error, remember that `a[b]` is just syntactic sugar for pointer addition
followed by dereference, so `1["ABC"]` is valid and equivalent to `"ABC"[1]`.

Reference:
C++23 §7.6.1.2 — Array subscript expression semantics
C++23 §7.6.6 — Pointer arithmetic rules
*/

#include <iostream>
int main() {
  std::cout << 1["ABC"];
}
