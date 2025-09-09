/*
Question #58
Source: CPP GeeksforGeeks

Question:
Write a C++ program to demonstrate operator overloading for the + operator in a Complex class.

My Answer:
✅ Output:

18 + 10i

Reason:
- The operator+ function is overloaded to add two Complex objects.
- The real and imaginary parts of the two objects are added separately.
- Returns a new Complex object containing the sum.
- Demonstrates how C++ allows custom behavior for standard operators.
*/

#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    // Overload '+' operator
    Complex operator+(Complex const& obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    void print() { cout << real << " + " << imag << "i\n"; }
};

int main()
{
    Complex c1(15, 5), c2(3, 5);
    Complex c3 = c1 + c2;
    c3.print();
}