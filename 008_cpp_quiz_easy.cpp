/*
Question #8
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: A

Reason:
- Class A defines a virtual function f().
- Class B overrides f() with its own implementation.
- However, g takes its parameter 'a' by value (A a), causing object slicing.
- When B b is passed to g, only the A subobject is copied into 'a'.
- The dynamic type of 'a' is now A, so virtual dispatch calls A::f().
- This results in printing "A" instead of "B".

If Wrong:
To get "B", pass by reference or pointer:
    void g(A& a) { a.f(); }

Reference:
C++23 §11.9.5 — Object slicing and polymorphic behavior
*/

#include <iostream>

class A {
public:
    virtual void f() { std::cout << "A"; }
};

class B : public A {
public:
    void f() { std::cout << "B"; }
};

void g(A a) { a.f(); }

int main() {
    B b;
    g(b); // prints A
}
