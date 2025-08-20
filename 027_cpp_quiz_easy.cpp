/*
Question #27
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: B

Reason:
- `B b;` is created.
- `std::cout << b;` calls `operator<<(std::ostream&, const A&)`.
- Inside `operator<<`, `a.put(o)` is called.
- `put` is virtual. `a` refers to a `B` object, so `B::put` runs.
- `B::put` writes 'B' to the stream.

If Wrong:
If `put` were not virtual, `A::put` would be called instead:
Output: A

Reference:
C++23 §11.7 — Virtual functions and dynamic dispatch rules
*/

#include <iostream>

struct A {
  virtual std::ostream &put(std::ostream &o) const {
    return o << 'A';
  }
};

struct B : A {
  virtual std::ostream &put(std::ostream &o) const {
    return o << 'B';
  }
};

std::ostream &operator<<(std::ostream &o, const A &a) {
  return a.put(o);
}

int main() {
  B b;
  std::cout << b;
}
