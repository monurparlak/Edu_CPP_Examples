/*
Question #52
Difficulty: 1
Source: CPP Quiz

My Answer:
✅ Output: AB

Reason:
Step-by-step:

1. `A a;`
   - An object of type `A` is created.
   - The constructor of `A` prints `"A"`.

2. `B b = a.createB();`
   - `createB()` is called, which executes `return B();`.
   - The constructor of `B` prints `"B"`.

3. Program ends. Destructors are invoked, but they do not print anything.

Execution order:
- `Ctor(A)` → `"A"`
- `Ctor(B)` → `"B"`

Final output: `"AB"`

--------------------------------------
If Wrong:
- If you expected `"BA"`, note that in `main()`, the statement `A a;` is executed first, 
  then `B b = a.createB();`.
- Constructors print according to execution order, not declaration order in the code.

Reference:
- C++23 §11.4.5 — Constructor execution order  
- C++23 §6.9.1 — Statement execution sequencing

--------------------------------------
Question:
According to the C++23 standard, what is the output of this program?
*/

#include <iostream>

class A;

class B {
public:
  B() { std::cout << "B"; }
  friend B A::createB();
};

class A {
public:
  A() { std::cout << "A"; }

  B createB() { return B(); }
};

int main() {
  A a;
  B b = a.createB();
}

