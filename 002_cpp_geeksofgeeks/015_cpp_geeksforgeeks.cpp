/*
Question #15
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Whether a Given Year is a Leap Year.

My Answer:
✅ Output: Leap Year

Reason:
- If year divisible by 400, it's leap.
- Else if divisible by 100, not leap.
- Else if divisible by 4, leap.
- Otherwise, not leap.

If Wrong:
Ensure the divisibility checks follow correct leap year rules.
*/

#include <iostream>
using namespace std;

bool checkYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int main() {
    int year = 2000;
    if (checkYear(year))
        cout << "Leap Year" << endl;
    else
        cout << "Not a Leap Year" << endl;
    return 0;
}
