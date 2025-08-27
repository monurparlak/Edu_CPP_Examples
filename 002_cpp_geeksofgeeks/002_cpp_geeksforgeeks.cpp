/*
Question #2
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find the Greatest Among Three Numbers.

My Answer:
✅ Output: The Greatest Among Three Numbers is : 30

Reason:
- Compare a, b, and c using if-else conditions.
- Print the largest number.

If Wrong:
Ensure all comparison cases are covered and correct number is printed.
*/

#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 30;

    cout << "The Greatest Among Three Numbers is : ";
    if (a >= b && a >= c)
        cout << a << endl;
    else if (b >= a && b >= c)
        cout << b << endl;
    else
        cout << c << endl;

    return 0;
}
