/*
Question #62
Source: CPP GeeksforGeeks

Question: Create a class to represent lengths in feet and inches, supporting addition and subtraction operations.

My Answer:
✅ Output:
11 feet and 4 inches
5 feet and 8 inches
5 feet and 8 inches

Reason:
- The class `inchFeet` encapsulates a length with feet and inches.
- Overloaded `+` operator adds two lengths; if inches >= 12, it converts to additional feet.
- Overloaded `-` operator subtracts two lengths; it handles borrowing 1 foot if inches of minuend < subtrahend.
- Copy constructor, default constructor, and utility functions allow easy use.
- In main, `a - b` correctly calculates 11'4" - 5'8" = 5'8".
*/

#include <bits/stdc++.h>
using namespace std;

// inch-feet length system datatype
struct c {
    double feet;
    double inch;
};

// inchFeet class
class inchFeet {
private:
    struct c length;

public:
    // constructors
    inchFeet() {}
    inchFeet(double feet, double inch)
    {
        length.feet = feet;
        length.inch = inch;
    }
    inchFeet(inchFeet& var)
    {
        length.feet = var.length.feet;
        length.inch = var.length.inch;
    }

    // utility functions
    void print()
    {
        cout << length.feet << " feet and " << length.inch << " inches" << endl;
    }

    double inches() { return length.inch; }
    double feet() { return length.feet; }

    // overloaded operators
    inchFeet operator+(inchFeet& obj1)
    {
        inchFeet var;
        var.length.feet = length.feet + obj1.length.feet;
        var.length.inch = length.inch + obj1.length.inch;
        if (var.length.inch >= 12.0) {
            var.length.feet++;
            var.length.inch -= 12.0;  // fixed bug: was var.length.inch - 12.0;
        }
        return var;
    }

    inchFeet operator-(inchFeet& obj1)
    {
        inchFeet var;
        struct c temp = length;
        if (temp.feet > obj1.length.feet || (temp.feet == obj1.length.feet && temp.inch >= obj1.length.inch)) {
            if (temp.inch < obj1.length.inch) {
                temp.feet--;
                temp.inch += 12;
            }
            var.length.feet = temp.feet - obj1.length.feet;
            var.length.inch = temp.inch - obj1.length.inch;
        } else {
            cout << "Negative Length is not Possible\n";
            var.length.feet = 0;
            var.length.inch = 0;
        }
        return var;
    }
};

// driver code
int main()
{
    inchFeet a(11, 4), b(5, 8);
    inchFeet c;
    c = a - b;

    a.print();
    b.print();
    c.print();

    return 0;
}
