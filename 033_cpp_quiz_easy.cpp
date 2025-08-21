/*
Question #33
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: G

Reason:
Step-by-step:

1. `f()` throws a `SpecialException` object by value.

2. `catch (GeneralException e)`:
   - The exception is caught **by value**, not by reference.
   - This causes **object slicing**: only the `GeneralException` subobject of the thrown `SpecialException` is copied into `e`.
   - The `SpecialException`-specific part is lost.

3. `e.print();`
   - `e` is now a plain `GeneralException` object.
   - Virtual dispatch calls `GeneralException::print()` → prints `"G"`.

If Wrong:
If you expected `"S"`, it’s because you assumed the dynamic type is preserved.  
To preserve the dynamic type and get `"S"`, the catch should be by reference:
```cpp
catch (GeneralException &e) { e.print(); }
Reference:
C++23 §15.3 — Catch clauses and object slicing rules
C++23 §12.7 — Virtual function call and dynamic dispatch
*/

#include <iostream>

struct GeneralException {
  virtual void print() { std::cout << "G"; }
};

struct SpecialException : public GeneralException {
  void print() override { std::cout << "S"; }
};

void f() { throw SpecialException(); }

int main() {
  try {
    f();
  }
  catch (GeneralException e) {
    e.print();
  }
}