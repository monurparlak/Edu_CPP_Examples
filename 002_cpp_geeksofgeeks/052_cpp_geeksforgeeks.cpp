/*
Question #52
Source: CPP GeeksforGeeks

Question:
Write a C++ program to convert a decimal number to its hexadecimal equivalent.

My Answer:
✅ Output:
Hexadecimal equivalent: 67

Reason:

Hexadecimal system is base-16; digits range from 0–9 and A–F.

The program repeatedly divides the decimal number by 16, storing remainders.

Remainders are mapped to hex digits and concatenated in reverse order.

Time Complexity: O(log16 N), where N is the decimal number.

Space Complexity: O(1) for calculation, O(log16 N) for the string.
*/

#include <iostream>
#include <string>
using namespace std;

string decimalToHexa(int decimal)
{
    string hexadecimal = "";
    char hexaDecimals[16]
        = { '0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    while (decimal > 0) {
        int remainder = decimal % 16;
        hexadecimal = hexaDecimals[remainder] + hexadecimal;
        decimal /= 16;
    }
    return hexadecimal;
}

int main()
{
    int decimal = 103;

    cout << "Hexadecimal equivalent: "
         << decimalToHexa(decimal) << endl;

    return 0;
}
