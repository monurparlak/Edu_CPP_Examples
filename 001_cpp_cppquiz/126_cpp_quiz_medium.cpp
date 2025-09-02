/*
Question #126
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 10

Reason:
- `foobar::x` is a **static member**, defined outside the class: `int foobar::x = foo();`
- At this point, **unqualified `foo()`** refers to **global `foo()`**, because:
  - Inside member initializer outside the class, class scope members **are not yet considered**
  - `foobar::foo()` requires `foobar::foo()` syntax
- So `foobar::x = foo();` → calls **global `int foo()`** → returns 10
- In `main()`, `std::cout << foobar::x;` → prints **10**

If Wrong:
- Some may expect 11; remember **static member initializer outside the class** does **not see class static members as unqualified names**.

Reference:
C++23 §12.6.2 — Static data member initialization and name lookup
*/

#include <iostream>
using namespace std;

int foo() { return 10; }

struct foobar {
    static int x;
    static int foo() { return 11; }
};

int foobar::x = foo(); // calls global foo(), not foobar::foo()

int main() {
    cout << foobar::x; // Output: 10
}
