/*
Question #44
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: YX

Reason:
Step-by-step:

1. `X arr[1];`
   - Creates an array with one `X` object, default-initialized.

2. `Y y1;`
   - Creates a `Y` object.

3. `arr[0] = y1;`
   - `arr[0]` is of type `X`, `y1` is of type `Y`.
   - Assignment from `Y` to `X` slices the object (object slicing).
   - Only the `X` subobject part of `y1` is copied into `arr[0]`.
   - The `Y`-specific part is lost.

4. `print(y1);`
   - `y1` is still a full `Y` object.
   - `print` takes a `const X&` but dynamic dispatch calls `Y::f()` → prints `"Y"`.

5. `print(arr[0]);`
   - `arr[0]` is a pure `X` object (due to slicing).
   - Virtual dispatch calls `X::f()` → prints `"X"`.

Concatenate: `"YX"`

If Wrong:
If you expect `"YY"`, you’re forgetting that `arr[0]` is not a `Y` after assignment — slicing removes derived parts, so virtual dispatch calls the base class method.

Reference:
C++23 §11.4.9 — Object slicing rules during copy/assignment
C++23 §12.7 — Virtual function call and dynamic dispatch
*/

#include <iostream>
struct X {
  virtual void f() const { std::cout << "X"; }
};

struct Y : public X {
  void f() const { std::cout << "Y"; }
};

void print(const X &x) { x.f(); }

int main() {
  X arr[1];
  Y y1;
  arr[0] = y1;
  print(y1);
  print(arr[0]);
}
