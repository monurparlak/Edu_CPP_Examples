/*
Question #30
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Print Hourglass Pattern of Stars.

My Answer:
✅ Output: (hourglass pattern with 5 rows)
 * * * * * * * * * 
   * * * * * * * 
     * * * * * 
       * * * 
         * 
       * * * 
     * * * * * 
   * * * * * * * 
 * * * * * * * * * 

Reason:
- Loop over 2*rows-1 to cover top and bottom halves.
- Calculate leading spaces based on row index.
- Print stars in decreasing and then increasing order to form hourglass.

If Wrong:
Ensure space and star counts are correct for symmetric hourglass.
*/

#include <iostream>
using namespace std;

void hourglass(int rows) {
    for (int i = 0; i < 2*rows-1; i++) {
        int comp = (i < rows) ? 2*i+1 : 2*(2*rows-i)-3;
        for (int j = 0; j < comp; j++) cout << ' ';
        for (int k = 0; k < 2*rows-comp; k++) cout << "* ";
        cout << '\n';
    }
}

int main() {
    hourglass(5);
    return 0;
}
