/*
Question #105
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: aAaA

Reason:
- Global `int i = 1;`
- First execution of `label:` → constructs `A a;` → prints `"a"`.
- `if (i--)` with `i = 1` → true, decrements i → `i = 0` → jumps to `label`.
- Jumps over an automatic variable `a`: before `goto label`, the old `a` must be destroyed → prints `"A"`.
- At `label:` again, a new `a` object is created → prints `"a"`.
- `if (i--)` now with `i = 0` → false, so no more jumps.
- At end of scope, the last `a` is destroyed → prints `"A"`.

So the sequence is:  
1. `"a"` (construct first)  
2. `"A"` (destroy before jump)  
3. `"a"` (construct second)  
4. `"A"` (destroy at scope exit)

Final output: `aAaA`

If Wrong:
If one forgets that `goto` crossing a local object’s scope triggers destruction, they might expect `aaA`.  
But the standard enforces destruction when leaving scope, even via `goto`.

Reference:
C++23 §6.7/2 — *If the flow of control passes through the definition of an automatic object, its lifetime begins. If it leaves the scope (including by goto), its destructor is called.*
*/

#include <iostream>

class A {
public:
  A() { std::cout << "a"; }
  ~A() { std::cout << "A"; }
};

int i = 1;

int main() {
label:
  A a;
  if (i--)
    goto label;
}
