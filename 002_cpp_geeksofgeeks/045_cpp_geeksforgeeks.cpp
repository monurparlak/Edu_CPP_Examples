/*
Question #45
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Print Maximum Value of unsigned int.

My Answer:
✅ Output: Max value possible : 4294967295

Reason:
- Initialize max = 0, then use bitwise NOT (~) to flip all bits.
- For 32-bit unsigned int, ~0 = 2^32 - 1 = 4294967295.

If Wrong:
Check your system’s unsigned int size; 32-bit assumed here.
*/

#include <iostream>
using namespace std;

int main() {
    unsigned int max = 0;
    max = ~max;
    cout << "Max value possible : " << max;
    return 0;
}
