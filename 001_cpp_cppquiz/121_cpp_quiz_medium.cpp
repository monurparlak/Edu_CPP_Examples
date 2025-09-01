/*
Question #121
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 20

Reason:
- The statement `x = (a, b);` uses the **comma operator**.
- Comma operator evaluates **left operand** (a → 10), discards the result.
- Then evaluates **right operand** (b → 20) and returns it.
- Assignment: x = (a, b) → x = 20
- Therefore, std::cout << x; prints 20.

If Wrong:
- If you expected 10, note that `x = a, b;` (without parentheses) behaves differently:
  - `x = a, b;` → parsed as `(x = a), b;` → x = 10, then b evaluated/discarded.

Reference:
C++23 §7.6.19 — Comma operator evaluation rules
*/

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;
    int x;
    x = (a, b);   // comma operator → x = b = 20
    cout << x;    // prints 20
    return 0;
}
