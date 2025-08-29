/*
Question #11
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Remove All Vowels from a String.

My Answer:
✅ Output: String without vowels: GksfrGks

Reason:
- Iterate through each character of the string.
- Skip vowels (a, e, i, o, u) in both lowercase and uppercase.
- Shift non-vowel characters to the left using index j.
- Nullify remaining characters and print the string.

If Wrong:
Check that both uppercase and lowercase vowels are included and shifting is correct.
*/

#include <iostream>
using namespace std;

int main() {
    string str = "GeeksforGeeks";
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&
            str[i]!='u'&&str[i]!='A'&&str[i]!='E'&&str[i]!='I'&&
            str[i]!='O'&&str[i]!='U')
            str[j++] = str[i];
    }

    while (j < str.size()) str[j++] = '\0';

    cout << "String without vowels: " << str << endl;
    return 0;
}
