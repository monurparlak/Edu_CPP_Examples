/*
Question #42
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Count the Sum of Numbers in a String.

My Answer:
✅ Output: Sum of numbers: 10

Reason:
- Iterate over each character of the string.
- Use isdigit() to check if character is a digit.
- Convert char to int by subtracting '0'.
- Accumulate the sum of all digits.

If Wrong:
Ensure characters are digits; non-digit characters are ignored.
*/

#include <iostream>
#include <string>
using namespace std;

int sum_of_numbers(string str) {
    int sum = 0;
    for (char ch : str) {
        if (isdigit(ch)) sum += ch - '0';
    }
    return sum;
}

int main() {
    string str = "1234";
    cout << "Sum of numbers: " << sum_of_numbers(str) << endl;
    return 0;
}
