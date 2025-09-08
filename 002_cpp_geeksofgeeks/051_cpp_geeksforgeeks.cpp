/*
Question #51
Source: CPP GeeksforGeeks

Question:
Write a C++ program to convert a decimal number
into its octal equivalent.

My Answer:
✅ Output:
Octal equivalent 67

Reason:
- Octal numbers are base-8.
- Algorithm:
  1. Initialize `octal = 0` and `place = 1`.
  2. While decimal number `temp` is not zero:
     - Take `lastDigit = temp % 8`.
     - Add `lastDigit * place` to `octal`.
     - Update `place *= 10`.
     - Update `temp /= 8`.
  3. Print `octal`.
- For decimal 55:
  55 ÷ 8 = 6 remainder 7 → octal is 67.

If Wrong:
- Avoid using direct decimal-to-octal libraries for learning purposes.
- Ensure multiplication by the correct place value.
*/

#include <iostream>
using namespace std;

int main() {
    int decimal = 55;
    int octal = 0, place = 1;

    int temp = decimal;
    while (temp) {
        int lastDigit = temp % 8;
        temp /= 8;
        octal += lastDigit * place;
        place *= 10;
    }

    cout << "Octal equivalent " << octal << endl;

    return 0;
}
