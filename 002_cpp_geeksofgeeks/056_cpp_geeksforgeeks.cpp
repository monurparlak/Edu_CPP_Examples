/*
Question #56
Source: CPP GeeksforGeeks

Question:
Write a C++ program to demonstrate abstraction using a class with private members and public methods.

✅ Output:

p = 1
q = 2

Reason:
- Abstraction hides internal details of a class and exposes only necessary functionalities.
- Private members p and q cannot be accessed directly; they are manipulated via public methods setter and display.
- This ensures data encapsulation and controlled access.
*/

#include <iostream>
using namespace std;

class implementAbstraction {
private:
    int p, q;

public:
    // Method to set values of private members
    void setter(int x, int y)
    {
        p = x;
        q = y;
    }

    void display()
    {
        cout << "p = " << p << endl;
        cout << "q = " << q << endl;
    }
};

int main()
{
    implementAbstraction obj;

    obj.setter(1, 2);   // Setting values
    obj.display();       // Displaying values

    return 0;
}