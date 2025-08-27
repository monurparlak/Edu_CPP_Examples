/*
Question #5
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check Whether a Character is a Vowel or Consonant.

My Answer:
✅ Output: e is a vowel.

Reason:
- First, check if the character is an alphabet using isalpha().
- Then check if it is one of 'a', 'e', 'i', 'o', 'u' (uppercase included).
- Print "vowel" or "consonant" accordingly.

If Wrong:
Ensure both uppercase and lowercase vowels are included and logic is correct.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch = 'e';

    if (isalpha(ch)) {
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
            ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            cout << ch << " is a vowel." << endl;
        else
            cout << ch << " is a consonant." << endl;
    } else {
        cout << ch << " is not an alphabet." << endl;
    }

    return 0;
}
