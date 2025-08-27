/*
Question #3
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Whether a Number is Even or Odd.

My Answer:
✅ Output: Odd

Reason:
- Define a function isEven() that returns true if n % 2 == 0.
- Call the function with the number.
- Print "Even" or "Odd" accordingly.

If Wrong:
Ensure modulo operation is correct and the conditional prints the right string.
*/

#include <iostream>
using namespace std;

bool isEven(int n) { return (n % 2 == 0); }

int main() {
    int n = 247;
    if (isEven(n))
        cout << "Even" << endl;
    else
        cout << "Odd" << endl;
    return 0;
}
