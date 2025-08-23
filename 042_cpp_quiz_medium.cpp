/*
Question #42
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 1133

Reason:
Step-by-step:

1. `A a1;`
   - Direct default initialization → calls `A()` → prints `"1"`.

2. `A a2{};`
   - Value initialization with empty braces.
   - Calls `A()` (since there is a user-provided default constructor) → prints `"1"`.

3. `A a3{ 1 };`
   - List-initialization with a single `int` element.
   - Overload resolution prefers `A(std::initializer_list<int>)` if viable.
   - `std::initializer_list<int>` constructor is viable here (from `{1}`) → prints `"3"`.

4. `A a4{ 1, 2 };`
   - List-initialization with two `int`s.
   - Only `A(std::initializer_list<int>)` can accept multiple ints in braces → prints `"3"`.

Concatenate: `"1133"`

If Wrong:
If you expect `"1123"`, you might think `A(int)` is chosen for `{1}`, but per §12.2.2.8, when list-initializing, the `std::initializer_list` constructor is given priority in overload resolution if it’s viable.

Reference:
C++23 §12.2.2.8 — List-initialization and overload resolution
C++23 §12.2.2.5 — Value-initialization rules
*/

#include <initializer_list>
#include <iostream>

struct A {
  A() { std::cout << "1"; }

  A(int) { std::cout << "2"; }

  A(std::initializer_list<int>) { std::cout << "3"; }
};

int main(int argc, char *argv[]) {
  A a1;
  A a2{};
  A a3{ 1 };
  A a4{ 1, 2 };
}
