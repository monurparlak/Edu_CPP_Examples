/*
Question #28
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Print a Diamond Pattern of Stars.

My Answer:
✅ Output: (diamond pattern with 5 rows)
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
* * * * * 
 * * * * 
  * * * 
   * * 
    *

Reason:
- First loop prints the top half: decrease spaces, increase stars.
- Second loop prints the bottom half: increase spaces, decrease stars.
- Each line prints stars separated by spaces.

If Wrong:
Ensure top and bottom halves align symmetrically with correct spaces.
*/

#include <iostream>
using namespace std;

void printDiamond(int n) {
    int space = n-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < space; j++) cout << " ";
        for (int j = 0; j <= i; j++) cout << "* ";
        cout << endl;
        space--;
    }

    space = 0;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < space; j++) cout << " ";
        for (int j = 0; j < i; j++) cout << "* ";
        cout << endl;
        space++;
    }
}

int main() {
    printDiamond(5);
    return 0;
}
