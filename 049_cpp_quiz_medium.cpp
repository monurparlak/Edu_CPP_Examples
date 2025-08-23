/*
Question #49
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 12310158

Reason:
Step-by-step:

1. `const C &c = C(1);`
   - A temporary `C(1)` is created → constructor prints `1`.
   - Bound to `const C&`, so its lifetime is extended until end of `main()`.

2. `C(2);`
   - Temporary `C(2)` is created → prints `2`.
   - Not bound to a reference, so destroyed at the end of the full expression.
   - Destructor runs → `i` is `2`, so prints `2 + 5 = 7`.

3. `C(3);`
   - Temporary `C(3)` is created → prints `3`.
   - Destroyed immediately after the statement ends.
   - Destructor prints `3 + 5 = 8`.

4. End of `main()`:
   - The temporary `C(1)` (bound to `c`) is destroyed.
   - Destructor prints `1 + 5 = 6`.

Execution order:
- Ctor(1) → `"1"`
- Ctor(2) → `"2"`
- Dtor(2) → `"7"`
- Ctor(3) → `"3"`
- Dtor(3) → `"8"`
- Dtor(1) → `"6"`

Concatenate: `"127386"`

If Wrong:
A common mistake is to think destruction happens strictly reverse to creation order
in all cases, but here, temporaries not bound to references are destroyed at the end
of their full expression (§6.7.7).

Reference:
C++23 §6.7.7 — Temporary object lifetime and destruction timing
C++23 §11.4.7 — Destructor behavior
*/

#include <iostream>

class C {
public:
  C(int i) : i(i) { std::cout << i; }
  ~C() { std::cout << i + 5; }

private:
  int i;
};

int main() {
  const C &c = C(1);
  C(2);
  C(3);
}
