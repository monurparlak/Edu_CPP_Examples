/*
Question #9
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: unspecified / may vary

Reason:
Step-by-step:

1. `int c = f(a, a);`
   - Both parameters refer to the same variable `a`.
   - Inside `f`: `a = 3; b = 4; return a + b;`
   - Here `a` and `b` are aliases to the same memory.

2. Behavior:
   - Writing to the same variable through multiple references without a 
     sequence point creates **unspecified behavior**.
   - Standard does not guarantee which value is read or written first.

3. `std::cout << a << b << c;`
   - `a` may be 3 or 4, `b` is 2, `c` may vary depending on evaluation order.
   - Output is therefore **unspecified**.

If Wrong:
- If you answered a fixed number like "334" or "344": incorrect, C++23 does 
  not define the evaluation order in this case.
- If you assumed compile error: code is valid, compiles fine.

Reference:
- C++23 §6.9.2/15 — Unspecified order of evaluation for function arguments
- C++23 §6.9.2/16 — Modifying a scalar multiple times without sequence point
*/
  
/* Actual Program Code: */

#include <iostream>

int f(int &a, int &b) {
  a = 3;
  b = 4;
  return a + b;
}

int main() {
  int a = 1;
  int b = 2;
  int c = f(a, a);
  std::cout << a << b << c;
}
