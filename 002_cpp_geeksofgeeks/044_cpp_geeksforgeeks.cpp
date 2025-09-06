/*
Question #44
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Swap Two Numbers Without Using a Temporary Variable.

My Answer:
✅ Output:
X : 3
Y : 4

After:
X : 4
Y : 3

Reason:
- Use arithmetic operations: x = x+y; y = x-y; x = x-y;
- This swaps values without a temporary variable.

If Wrong:
Ensure no overflow occurs for large integers when using x+y.
*/

#include <iostream>
using namespace std;

int main() {
    int x = 3, y = 4;
    cout << "X : " << x << endl;
    cout << "Y : " << y << endl;

    x = x + y;
    y = x - y;
    x = x - y;

    cout << endl << "After:" << endl;
    cout << "X : " << x << endl;
    cout << "Y : " << y << endl;

    return 0;
}
