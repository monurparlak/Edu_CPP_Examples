/*
Question #10
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Remove All Vowels from a String.

My Answer:
✅ Output: GksfrGks

Reason:
- Iterate through each character of the string.
- Check if it's a vowel (a, e, i, o, u, A, E, I, O, U).
- Non-vowels are shifted to the left using index j.
- Remaining characters set to '\0'.
- Print the resulting string without vowels.

If Wrong:
Ensure both uppercase and lowercase vowels are checked and shifting is correct.
*/

#include <iostream>
using namespace std;

int main() {
    int j = 0;
    string str = "GeeksforGeeks";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' &&
            str[i]!='u' && str[i]!='A' && str[i]!='E' && str[i]!='I' &&
            str[i]!='O' && str[i]!='U') {
            str[j++] = str[i];
        }
    }

    while (j < str.size()) {
        str[j++] = '\0';
    }

    cout << "String without vowels: " << str << endl;
    return 0;
}
