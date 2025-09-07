/*
Question #48
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Convert Octal to Decimal.

My Answer:
✅ Output: Decimal equivalent is: 55

Reason:
- Extract each digit from right to left using modulo 10.
- Multiply each digit by 8^position and sum for decimal.
- Increment position after each digit processed.

If Wrong:
Ensure input octal number does not contain digits >=8.
*/

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int oct = 67, dec = 0, place = 0;
    int temp = oct;
    while (temp) {
        int lastDigit = temp % 10;
        dec += lastDigit * pow(8, place++);
        temp /= 10;
    }
    cout << "Decimal equivalent is: " << dec << endl;
    return 0;
}
