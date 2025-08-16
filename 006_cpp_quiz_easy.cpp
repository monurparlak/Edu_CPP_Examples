/*
Question #6
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 012012

Reason:
Step-by-step:

1. `for (int i = 0; i < 3; i++)`
   - Post-increment: i starts at 0, prints 0,1,2 in order.
   - Prints "012".

2. `for (int i = 0; i < 3; ++i)`
   - Pre-increment: i starts at 0, prints 0,1,2 in order.
   - Prints "012".

3. Concatenate outputs: "012012".

If Wrong:
- If you thought post-increment prints differently: both loops output 0,1,2.
- If you expected a compile error: no error occurs; both loops are valid.

Reference:
- C++23 §6.5.3 — for statement and increment operators
*/
  
/* Actual Program Code: */

#include <iostream>

int main() {
  for (int i = 0; i < 3; i++)
    std::cout << i;
  for (int i = 0; i < 3; ++i)
    std::cout << i;
}
