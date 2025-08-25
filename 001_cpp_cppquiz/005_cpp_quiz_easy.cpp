/*
Question #5
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: BA

Reason:
Step-by-step:

1. `C()` constructor is called.
   - Member variables are initialized in the order of declaration in the class,
     not in the order listed in the initializer list.

2. `class C` members:
   - `B b;` is declared first → B's constructor runs → prints "B".
   - `A a;` is declared second → A's constructor runs → prints "A".

3. Concatenate the outputs: "BA".

If Wrong:
- If you expected "AB": you might think initializer list order matters,
  but **member declaration order always determines initialization order**.
- If you answered "compile error": the code is valid, no error occurs.

Reference:
- C++23 §11.9.4.6 — Member initializer list and initialization order
*/
  
/* Actual Program Code: */

#include <iostream>

struct A {
  A() { std::cout << "A"; }
};
struct B {
  B() { std::cout << "B"; }
};

class C {
public:
  C() : a(), b() {}

private:
  B b;
  A a;
};

int main()
{
    C();
}
