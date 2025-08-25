/*
Question #32
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: abbcb

Reason:
Step-by-step:
1. `X x;`
   - Calls default constructor `X()` → prints `"a"`.

2. `X y(x);`
   - Calls copy constructor `X(const X&)` → prints `"b"`.

3. `X z = y;`
   - Also calls copy constructor `X(const X&)` → prints `"b"`.

4. `z = x;`
   - Calls copy assignment operator `operator=(const X&)` → prints `"c"`.

Final output order:  
`a` (default ctor)  
`b` (copy ctor for `y`)  
`b` (copy ctor for `z`)  
`c` (copy assignment for `z = x`)  

Concatenate: `"abbc"`

⚠ Correction: Actually, I initially thought `"abbcb"`, but there is no extra `"b"` after assignment — assignment doesn’t call copy constructor. So final correct output is `"abbc"`.

If Wrong:
If you get `"abbcb"`, you might be mistakenly thinking the assignment
also invokes a copy constructor, but it does not — only `operator=` runs.

Reference:
C++23 §11.4.5 — Copy constructors
C++23 §11.4.6 — Copy assignment operators
*/

#include <iostream>

struct X {
  X() { std::cout << "a"; }
  X(const X &x) { std::cout << "b"; }
  const X &operator=(const X &x) {
    std::cout << "c";
    return *this;
  }
};

int main() {
  X x;
  X y(x);
  X z = y;
  z = x;
}
