/*
Question #59
Source: CPP GeeksforGeeks

Question:
Write a C++ program to demonstrate function overloading / compile-time and run-time polymorphism using virtual functions.

My Answer:
✅ Output:

print derived class
show base class


Reason:

print() is a virtual function, so the call is resolved at runtime (dynamic binding) → derived class version runs.

show() is non-virtual, so the call is resolved at compile-time (static binding) → base class version runs.

Demonstrates difference between compile-time and run-time polymorphism.
*/

#include <iostream>
using namespace std;

class base {
public:
    virtual void print()
    {
        cout << "print base class" << endl;
    }

    void show() { cout << "show base class" << endl; }
};

class derived : public base {
public:
    void print() { cout << "print derived class" << endl; }

    void show() { cout << "show derived class" << endl; }
};

int main()
{
    base* bptr;
    derived d;
    bptr = &d;

    bptr->print(); // Virtual -->> derived class
    bptr->show();  // Non-virtual -->> base class

    return 0;
}