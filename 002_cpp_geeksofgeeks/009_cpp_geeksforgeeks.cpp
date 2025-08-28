/*
Question #9
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Count the Number of Vowels in a String.

My Answer:
✅ Output: Number of vowels in the string: 9

Reason:
- Iterate through each character of the string.
- Check if it's a vowel (a, e, i, o, u, A, E, I, O, U).
- Increment the vowel counter for each vowel found.
- Print the total count.

If Wrong:
Ensure both uppercase and lowercase vowels are included in the check.
*/

#include <iostream>
using namespace std;

int main() {
    string str = "GeeksforGeeks to the moon";
    int vowels = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||
            str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||
            str[i]=='O'||str[i]=='U') {
            vowels++;
        }
    }

    cout << "Number of vowels in the string: " << vowels << endl;
    return 0;
}
