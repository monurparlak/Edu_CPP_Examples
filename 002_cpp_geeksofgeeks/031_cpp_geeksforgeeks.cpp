/*
Question #33
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to print the star pattern (butterfly pattern).

My Answer:
✅ Output:
*         * 
* *     * * 
* * * * * * 
* * * * * * 
* *     * * 
*         * 

Reason:
- Upper part: Print stars row by row, leave spaces in the middle, and complete the right side with stars.
- Lower part: Repeat the same in reverse order.
- The middle spacing is calculated as `2*(n-i)` to align properly.

If Wrong:
- Check the number of spaces and stars. Review the loop limits `i <= n` and `i >= 0`.
*/

#include <iostream>
using namespace std;

void pattern(int n)
{
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }

        int spaces = 2 * (n - i);
        for (int j = 0; j < spaces; j++) {
            cout << "  ";
        }

        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }

        cout << endl;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }

        int spaces = 2 * (n - i);
        for (int j = 0; j < spaces; j++) {
            cout << "  ";
        }

        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }

        cout << endl;
    }
}
