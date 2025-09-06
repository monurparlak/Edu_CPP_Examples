/*
Question #43
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Print All Natural Numbers up to N Without Using a Semicolon.

My Answer:
✅ Output: 1 2 3 4 5 6 7 8 9 10

Reason:
- Use recursion and short-circuiting of logical AND (&&).
- cout returns an ostream object convertible to bool.
- The if statement avoids using a semicolon to print numbers.
- Increment x recursively until it reaches N.

If Wrong:
Check static variable initialization and recursion termination.
*/

#include <iostream>
using namespace std;
#define N 10

int main() {
    static int x = 1;
    if (cout << x << " " && x++ < N && main()) { }
    return 0;
}
