/*
Question #1
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Whether a Number is a Positive or Negative Number.

My Answer:
✅ Output: -100 is a negative number.

Reason:
- The program checks if the number is greater than or equal to 0.
- If true, it prints that the number is positive; otherwise, it prints that the number is negative.
- Since the number is -100, the output indicates it's a negative number.

If Wrong:
If you expected a different output, ensure that the number is correctly assigned and that the comparison operator is used properly.
*/

#include <iostream>
using namespace std;

int main() {
    int number = -100;
    if (number >= 0) {
        cout << number << " is a positive number." << endl;
    } else {
        cout << number << " is a negative number." << endl;
    }
    return 0;
}
