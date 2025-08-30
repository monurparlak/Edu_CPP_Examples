/*
Question #18
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Whether a Number is an Armstrong Number.

My Answer:
✅ Output: Yes, it is Armstrong Number

Reason:
- Store the original number in temp.
- Sum the cubes of each digit.
- If sum equals original number, it's Armstrong.

If Wrong:
Ensure each digit is cubed and summed correctly; compare with original number.
*/

#include <iostream>
using namespace std;

int main() {
    int n = 153;
    int temp = n, ans = 0;

    while (n > 0) {
        int rem = n % 10;
        ans += rem * rem * rem;
        n /= 10;
    }

    if (temp == ans)
        cout << "Yes, it is Armstrong Number" << endl;
    else
        cout << "No, it is not an Armstrong Number" << endl;

    return 0;
}
