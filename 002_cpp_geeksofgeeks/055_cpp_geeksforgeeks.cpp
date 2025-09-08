/*
Question #55
Source: CPP GeeksforGeeks

Question:
Write a C++ program to demonstrate encapsulation by using private data members and public setter/getter methods.

✅ Output:

13

Reason:
- Encapsulation binds data and methods together and hides the internal state of an object.
- The private member x cannot be accessed directly; it can only be modified or accessed via setter and getter functions.
- This ensures controlled access and data integrity.
*/

#include <iostream>
using namespace std;

class Encapsulation {
private:
    int x;  // Private data hidden from outside

public:
    // Setter function to set value of x
    void setter(int a) { x = a; }

    // Getter function to get value of x
    int getter() { return x; }
};

int main()
{
    Encapsulation obj;

    obj.setter(13);          // Set value
    cout << obj.getter();    // Get value

    return 0;
}