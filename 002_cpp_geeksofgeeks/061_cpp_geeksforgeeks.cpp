/*
Question #61
Source: CPP GeeksforGeeks

Question: Create a class for complex numbers supporting addition, subtraction, and multiplication.

My Answer:
✅ Output:
11 + i12
5 + i8
16 + i20

Reason:
- The `Complex` class encapsulates a complex number with real and imaginary parts.
- Overloaded `+` adds two complex numbers: (a+bi) + (c+di) = (a+c) + i(b+d)
- Overloaded `-` subtracts: (a+bi) - (c+di) = (a-c) + i(b-d)
- Overloaded `*` multiplies: (a+bi)*(c+di) = (ac - bd) + i(ad + bc)
- Utility functions print the complex number and allow access to real and imaginary parts.
- Copy constructor and default constructor allow flexible object creation.
- In main, `c = a + b` correctly computes 11 + 12i + 5 + 8i = 16 + 20i
*/

#include <bits/stdc++.h>
using namespace std;

// complex number datatype
struct c {
    double real;
    double img;
};

// Complex class
class Complex {
private:
    struct c num;

public:
    // constructors
    Complex() {}
    Complex(double real, double img)
    {
        num.real = real;
        num.img = img;
    }
    Complex(Complex& var)
    {
        num.real = var.num.real;
        num.img = var.num.img;
    }

    // utility functions
    void print()
    {
        cout << num.real << " + i" << num.img << endl;
    }

    double imag() { return num.img; }
    double real() { return num.real; }

    // overloaded operators
    Complex operator+(Complex& obj1)
    {
        Complex var;
        var.num.real = num.real + obj1.num.real;
        var.num.img = num.img + obj1.num.img;
        return var;
    }

    Complex operator-(Complex& obj1)
    {
        Complex var;
        var.num.real = num.real - obj1.num.real;
        var.num.img = num.img - obj1.num.img;
        return var;
    }

    Complex operator*(Complex& obj1)
    {
        Complex var;
        var.num.real = num.real * obj1.num.real - num.img * obj1.num.img;
        var.num.img = num.real * obj1.num.img + num.img * obj1.num.real;
        return var;
    }
};

// driver code
int main()
{
    Complex a(11, 12), b(5, 8);
    Complex c;
    c = a + b;

    a.print();
    b.print();
    c.print();

    return 0;
}
