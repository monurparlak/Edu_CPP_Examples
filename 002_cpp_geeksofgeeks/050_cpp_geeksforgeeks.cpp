/*
Question #50
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Convert a Decimal Number to Binary.

My Answer:
✅ Output: Binary equivalent: 00000000000000000000000000000111

Reason:
- Use C++ std::bitset<32> to represent 32-bit binary.
- Initialize bitset with decimal number.
- Printing the bitset gives binary representation.

If Wrong:
Ensure the number fits in 32 bits; leading zeros are shown by bitset.
*/

#include <bitset>
#include <iostream>
using namespace std;

int main() {
    int decimal = 7;
    bitset<32> binary(decimal);
    cout << "Binary equivalent: " << binary << endl;
    return 0;
}
