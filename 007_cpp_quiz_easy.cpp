/*
Question #7
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: A

Reason:
- Class B publicly inherits from A and hides A::f with its own f().
- However, f() in A is not declared virtual.
- When g takes an A& and calls a.f(), the call is resolved at compile time
  based on the static type of 'a', which is A.
- Therefore, A::f() is invoked, printing "A".
- This is an example of static (compile-time) dispatch.

If Wrong:
To get "B", make A::f virtual:
    virtual void f() { std::cout << "A"; }

Reference:
C++23 §11.7.3 — Virtual functions and dynamic dispatch
*/

#include <iostream>

class A {
public:
    void f() { std::cout << "A"; }
};

class B : public A {
public:
    void f() { std::cout << "B"; }
};

void g(A &a) { a.f(); }

int main() {
    B b;
    g(b); // prints A
}
