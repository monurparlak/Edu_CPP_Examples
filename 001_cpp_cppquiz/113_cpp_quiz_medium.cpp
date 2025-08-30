/*
Question #113
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 1 3 2

Reason:
- There are three f functions:

  1) Primary template: template<typename T> void f(T) { cout << 1; }
  2) Explicit specialization: template<> void f(int) { cout << 2; }
  3) Non-template overload: void f(int) { cout << 3; }

- First call: f(0.0);
  - 0.0 is double.
  - Matches primary template f(T) with T = double → prints 1.

- Second call: f(0);
  - 0 is int.
  - Candidates: template<> void f(int) and void f(int)
  - Non-template function is **preferred over any template** in overload resolution.
  - Therefore, void f(int) → prints 3.

- Third call: f<>(0);
  - Using empty template argument list forces the compiler to consider **only templates**.
  - Primary template specialization for int exists: template<> void f(int) → prints 2.

If Wrong:
- If you expected all template calls to pick specialization automatically, note that
  non-template overloads are preferred unless you force template instantiation
  with f<> syntax.

Reference:
C++23 §13.8 — Function template specializations and overload resolution
*/

#include <iostream>
using namespace std;

template<typename T>
void f(T) { cout << 1; }

template<>
void f(int) { cout << 2; }

void f(int) { cout << 3; }

int main() {
    f(0.0); // 1
    f(0);   // 3
    f<>(0); // 2
    return 0; // Output: 1 3 2
}
