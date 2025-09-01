/*
Question #29
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Print a Pyramid Pattern of Stars.

My Answer:
✅ Output: (pyramid pattern with 5 rows)
        * 
       * * 
      * * * 
     * * * * 
    * * * * *

Reason:
- Initialize k = 2*n-2 for leading spaces.
- Loop i from 0 to n-1.
- Print k spaces, then print i+1 stars with spaces.
- Decrease k by 1 each row.

If Wrong:
Ensure alignment with spaces and correct number of stars per row.
*/

#include <iostream>
using namespace std;

void pattern(int n) {
    int k = 2*n-2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) cout << " ";
        k--;
        for (int j = 0; j <= i; j++) cout << "* ";
        cout << endl;
    }
}

int main() {
    int n = 5;
    pattern(n);
    return 0;
}
