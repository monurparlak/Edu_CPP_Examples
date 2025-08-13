/*
Question #9
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: undefined behavior

Reason:
- In main, f is called with f(a, a), so both parameters bind to the same int.
- Inside f, 'a = 3;' and 'b = 4;' modify the same variable without an
  intervening sequence point, and the value is read to compute return value.
- This causes unsequenced modifications to the same scalar object.
- According to the standard, unsequenced modifications on the same object
  lead to undefined behavior.
- Therefore, the output is not defined and may vary.

If Wrong:
To make behavior defined, pass different objects:
    int c = f(a, b);

Reference:
C++23 §6.9.1 — Unsequenced modifications and undefined behavior
*/

#include <iostream>

int f(int &a, int &b) {
    a = 3;
    b = 4;
    return a + b;
}

int main() {
    int a = 1;
    int b = 2;
    int c = f(a, a); // UB: modifies same variable twice without sequencing
    std::cout << a << b << c;
}
