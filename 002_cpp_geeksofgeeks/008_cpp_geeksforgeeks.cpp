/*
Question #8
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Toggle Each Character in a String.

My Answer:
✅ Output: Toggled string: gEEKSFORgEEKS

Reason:
- Iterate through each character of the string.
- If the character is lowercase, convert to uppercase.
- If the character is uppercase, convert to lowercase.
- Print the toggled string.

If Wrong:
Ensure that both islower() and isupper() checks are correct and cover all chars.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str = "GeeksforGeeks";

    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i]))
            str[i] = toupper(str[i]);
        else if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }

    cout << "Toggled string: " << str << endl;
    return 0;
}
