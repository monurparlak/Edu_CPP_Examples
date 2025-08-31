/*
Question #120
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 10

Reason:
- In the statement 'x = a, b;', the operator precedence rules apply.
- The assignment operator '=' has **higher precedence** than the comma ','.
- So the expression is parsed as: (x = a), b;
- First, 'x = a;' executes, assigning 10 to x.
- Then the result of that assignment (which is 10) is discarded, and the
  comma operator evaluates and yields 'b' (which is 20), but its result is
  not used because there's no assignment left.
- Therefore, 'x' holds the value 10.
- When printed, the output is 10.

If Wrong:
If you expected 20, note that would only be true if parentheses forced
evaluation like: x = (a, b); // then x would be 20.

Reference:
C++23 §7.6.19 — Operator precedence and associativity (assignment vs comma)
*/

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;
    int x;
    x = a, b;   // parsed as (x = a), b
    cout << x;  // prints 10
    return 0;
}
