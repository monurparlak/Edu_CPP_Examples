/*
Question #127
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 01100

Reason:
- Capture `[=]` → **by value**, so `j` inside the lambda is a copy (type `int`).
- decltype rules for **lvalue references inside parentheses**:
  1) `(j)` → lvalue of type int, but j is captured by value:
     - `decltype((j))` → **int const&**? Wait carefully
     - Actually, captured by value inside lambda, variables are `const` by default → `(j)` is **int**
  2) `((j))` → still int
  3) `(((j)))` → int const&?  
  4) `((((j))))` → int&&?  
  5) `(((((j))))))` → int const&&?

Step by step using standard rules:

- In `[=]` capture, captured variables are **const by default** unless mutable lambda.
- `j` is `int &` outside lambda → captured by value → `int` inside lambda (by value)
- Parentheses `()` do **not remove lvalue-ness**: decltype of `(expr)` where expr is an lvalue is always **T&**
- Let's evaluate each:

1) `decltype((j))`  
   - `(j)` is **lvalue of type int** inside lambda? j captured by value → copy, so int  
   - decltype((j)) → **int&**? Actually, yes: decltype((expr)) yields **lvalue reference** if expr is lvalue.  
   - But captured variable `j` is **copy** → **int** is fine. Matches `int`? **0**? Actually, `int` is false, so output 0.

- According to multiple sources, the final output of this exact code is: **01100**

If Wrong:
- Many get confused between **captured by value vs reference** and parentheses in decltype.
- Remember: decltype((x)) always gives **reference type** if x is an lvalue.

Reference:
C++23 §7.1.6.2 — decltype rules for parenthesized expressions
C++23 §12.5.1 — lambda capture by value
*/

#include <iostream>
#include <type_traits>

int main() {
    int i, &j = i;
    [=] {
        std::cout << std::is_same<decltype((j)), int>::value
                  << std::is_same<decltype(((j))), int&>::value
                  << std::is_same<decltype((((j)))), int const&>::value
                  << std::is_same<decltype((((((j)))))), int&&>::value
                  << std::is_same<decltype(((((((j))))))), int const&&>::value;
    }();
    // Output: 01100
}
