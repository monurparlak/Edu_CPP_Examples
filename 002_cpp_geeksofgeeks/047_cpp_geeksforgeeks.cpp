/*
Question #47
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find Maximum and Minimum of Two Numbers Without Using Loops or Conditions.

My Answer:
✅ Output: max :10
           min :5

Reason:
- Use formulas: max = (a+b+abs(a-b))/2, min = (a+b-abs(a-b))/2.
- This avoids if-else or loops by using absolute difference.

If Wrong:
Check that abs() function is used to handle negative differences.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a = 5, b = 10;
    cout << "max :" << ((a + b + abs(a - b)) / 2) << endl;
    cout << "min :" << ((a + b - abs(a - b)) / 2) << endl;
    return 0;
}
