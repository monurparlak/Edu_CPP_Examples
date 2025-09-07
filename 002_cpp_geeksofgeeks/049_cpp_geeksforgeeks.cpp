/*
Question #49
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Convert Hexadecimal to Decimal.

My Answer:
✅ Output: Decimal equivalent 103

Reason:
- Traverse the hex string from right to left.
- Convert each hex char to decimal using ASCII manipulation.
- Multiply by 16^position and sum to get final decimal value.

If Wrong:
Ensure both uppercase and lowercase hex digits are handled.
*/

#include <cmath>
#include <iostream>
using namespace std;

int hexToDecimal(char hexDigit) {
    if (hexDigit >= '0' && hexDigit <= '9') return hexDigit - '0';
    else if (hexDigit >= 'A' && hexDigit <= 'F') return hexDigit - 'A' + 10;
    else if (hexDigit >= 'a' && hexDigit <= 'f') return hexDigit - 'a' + 10;
    return -1;
}

int main() {
    string hex = "67";
    int decimal = 0, place = 0;
    int n = hex.length();
    for (int i = n - 1; i >= 0; i--) {
        decimal += hexToDecimal(hex[i]) * pow(16, place++);
    }
    cout << "Decimal equivalent " << decimal << endl;
    return 0;
}
