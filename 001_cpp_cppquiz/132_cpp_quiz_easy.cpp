/*
Question #132
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 11

Reason:
- Function `bar` has a default parameter: `int i = foo()`
- In C++, **default arguments are evaluated at the call site** **each time** the function is called.
- Step by step:

1) `bar();`
   - No argument provided → default argument `foo()` evaluated
   - Calls `foo()` → prints 1

2) `bar();`
   - Again, no argument → default argument `foo()` evaluated
   - Calls `foo()` → prints 1

- Therefore, output: **11**

If Wrong:
- Some may expect `foo()` to be called only once; remember that **default arguments are re-evaluated on each call**.

Reference:
C++23 §9.3.5 — Default arguments evaluation
*/

#include <iostream>
using namespace std;

int foo() {
    cout << 1;
    return 1;
}

void bar(int i = foo()) {}

int main() {
    bar(); // prints 1
    bar(); // prints 1
    // Output: 11
}
