/*
Question #6
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 012012

Reason:
- First loop: i = 0,1,2 → prints 012.
- Second loop: new i declared, again 0,1,2 → prints 012.
- Combined output: 012012.
- The increment form (i++ vs ++i) makes no difference here, since the
  increment value isn't used in the loop body.

If Wrong:
If you wanted numbers separated or on new lines:
    std::cout << i << '\n';

Reference:
C++23 §6.5.4 — For statement execution rules
*/

#include <iostream>

int main() {
    for (int i = 0; i < 3; i++)
        std::cout << i; // prints 012
    for (int i = 0; i < 3; ++i)
        std::cout << i; // prints 012
}
