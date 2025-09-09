/*
Question #57
Source: CPP GeeksforGeeks

Question:
Write a C++ program to demonstrate function overloading (compile-time polymorphism) in a class.

✅ Output:

value of x is 10
value of x is 5.321
value of x and y is 94, 32

Reason:
- Function overloading allows multiple functions with the same name but different parameter lists.
- The compiler determines which function to call based on the arguments at compile time.
- Demonstrates compile-time polymorphism in C++.
*/

#include <iostream>
using namespace std;

class Geeks {
public:
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    }

    void func(double x)
    {
        cout << "value of x is " << x << endl;
    }

    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};

int main()
{
    Geeks obj1;

    obj1.func(10);       // Calls func(int)
    obj1.func(5.321);    // Calls func(double)
    obj1.func(94, 32);   // Calls func(int, int)

    return 0;
}