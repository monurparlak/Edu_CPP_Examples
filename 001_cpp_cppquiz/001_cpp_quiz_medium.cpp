/*
Question #1
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 1

Reason:
Step-by-step:

1. `int i = 42;`
   - `i` is a non-const lvalue of type `int`.

2. `f(i);`
   - Candidate functions:
     - `template <class T> void f(T &i)` → deduces `T = int`, exact match.
     - `template <> void f(const int &i)` → requires binding to const int&, 
       allowed but not a better match than exact int&.

3. Overload resolution:
   - Exact match (`int&`) is preferred over binding to `const int&`.
   - So `f(T&)` is called → prints "1".

Concatenate (Final Result): "1"

If Wrong:
- If you answered "2": specialization is not always stronger. `int&` is preferred.
- If you answered "compile error": both overloads are valid, no error occurs.
- If you answered "undefined/unspecified": overload resolution is unambiguous.

Reference:
- C++23 §13.10.3.2 — Overload resolution rules
- C++23 §13.7.7 — Explicit specialization rules
*/

/* Actual Program Code: */

#include <iostream>

template <class T> void f(T &i) { std::cout << 1; }
template <> void f(const int &i) { std::cout << 2; }

int main() {
  int i = 42;
  f(i);
}
