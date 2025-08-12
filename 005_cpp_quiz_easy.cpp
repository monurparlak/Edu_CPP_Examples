/*
Question #5
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: BA

Reason:
- Class C has two data members: b (type B) and a (type A).
- Even though the constructor initializer list writes a() then b(),
  the actual construction order is determined by member declaration order.
- Members are constructed in the order they are declared in the class,
  and destroyed in reverse order.
- Here, b is declared before a, so B's constructor runs first → prints B.
- Then A's constructor runs → prints A.
- Combined output: BA.

If Wrong:
To output AB, declare a before b in the class definition.

Reference:
C++23 §11.9.3 — Order of initialization of class members
*/

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
    C(); // prints BA
}
