/*
================================================================================
HackerRank C++ Challenge: Classes - Box
================================================================================

Objective:
----------
- Learn to define and use classes in C++.
- Implement constructors, copy constructors, member functions, and operator overloading.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Class Declaration:
   class Box {
       private:
           int l, b, h;
       public:
           Box();
           Box(int length, int breadth, int height);
           Box(const Box& B);
           int getLength();
           int getBreadth();
           int getHeight();
           long long CalculateVolume();
           bool operator<(const Box& B);
           friend ostream& operator<<(ostream& out, const Box& B);
   };

2. Constructors:
   - Default constructor initializes all dimensions to 0.
   - Parameterized constructor initializes dimensions to given values.
   - Copy constructor creates a new object with the same dimensions as an existing Box.

3. Member Functions:
   - Accessors: getLength(), getBreadth(), getHeight()
   - CalculateVolume(): returns product of dimensions

4. Operator Overloading:
   - operator< compares boxes based on given rules.
   - operator<< prints box dimensions in "l b h" format.

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- Multiple queries (handled in the check2() function in the main program).
- Queries include creating boxes, comparing, printing volume, and copying boxes.

Example Input:
5
2 1 2 3
3 1 2 3
4
1
5

Expected Output:
1 2 3
Lesser
6
1 2 3
1 2 3
*/

#include <bits/stdc++.h>
using namespace std;

// ==============================
// Box Class Definition
// ==============================
class Box {
private:
    int l, b, h; // length, breadth, height

public:
    // ------------------------------
    // Default Constructor
    // ------------------------------
    Box() : l(0), b(0), h(0) {}

    // ------------------------------
    // Parameterized Constructor
    // ------------------------------
    Box(int length, int breadth, int height) : l(length), b(breadth), h(height) {}

    // ------------------------------
    // Copy Constructor
    // ------------------------------
    Box(const Box& B) : l(B.l), b(B.b), h(B.h) {}

    // ------------------------------
    // Getter Functions
    // ------------------------------
    int getLength() const { return l; }
    int getBreadth() const { return b; }
    int getHeight() const { return h; }

    // ------------------------------
    // Calculate Volume
    // ------------------------------
    long long CalculateVolume() const {
        return static_cast<long long>(l) * b * h;
    }

    // ------------------------------
    // Overload operator< for Box comparison
    // ------------------------------
    bool operator<(const Box& B) const {
        if (l < B.l) return true;
        if (l == B.l && b < B.b) return true;
        if (l == B.l && b == B.b && h < B.h) return true;
        return false;
    }

    // ------------------------------
    // Overload operator<< for output
    // ------------------------------
    friend ostream& operator<<(ostream& out, const Box& B) {
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
};

// ==============================
// Function to handle queries
// ==============================
void check2() {
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cout << temp << endl; // print current Box
        } else if (type == 2) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        } else if (type == 3) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp) cout << "Lesser\n";
            else cout << "Greater\n";
        } else if (type == 4) {
            cout << temp.CalculateVolume() << endl;
        } else if (type == 5) {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main() {
    check2();
    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Use classes to encapsulate related data and functions.
2. Constructors allow for flexible initialization.
3. Copy constructors are important when objects are passed by value.
4. Operator overloading can make objects behave like built-in types.
5. Use 'friend' keyword to allow operator<< access to private members.
================================================================================
*/

