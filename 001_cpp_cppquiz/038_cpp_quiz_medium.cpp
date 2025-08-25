/*
Question #38
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 11

Reason:
Step-by-step:

1. `int a = 0;`
   - Simple integer variable `a` initialized to 0.

2. `decltype((a)) b = a;`
   - `decltype((a))` — note the double parentheses: `(a)` is an **lvalue expression**.
   - According to the rules of `decltype`:
     - `decltype(expression)` yields `T&` if `expression` is an lvalue.
   - Therefore, `decltype((a))` is `int&`.
   - `b` is a reference to `a`.

3. `b++;`
   - Increments `b`, which is a reference to `a`.
   - `a` becomes 1, `b` is also 1.

4. `std::cout << a << b;`
   - Both `a` and `b` are now 1 → prints `"11"`.

If Wrong:
If you expected `01`, you might have thought `decltype((a))` is just `int`,
but the parentheses create an **lvalue expression**, so the type is actually `int&`.

Reference:
C++23 §11.4.5.2 — `decltype` rules for lvalue expressions
*/

#include <iostream>

int main() {
  int a = 0;
  decltype((a)) b = a;
  b++;
  std::cout << a << b;
}
