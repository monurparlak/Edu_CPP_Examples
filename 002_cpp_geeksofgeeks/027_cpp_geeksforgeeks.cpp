/*
Question #27
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Check if Two Strings Are Anagrams.

My Answer:
✅ Output: The two strings are not anagram of each other

Reason:
- Use two count arrays (size 256) for character frequencies.
- Increment counts for each character in both strings.
- Compare counts; if any mismatch, strings aren't anagrams.

If Wrong:
Ensure both strings are of same length and count arrays are correct.
*/

#include <iostream>
using namespace std;

#define NO_OF_CHARS 256

bool areAnagram(char* str1, char* str2) {
    int count1[NO_OF_CHARS] = {0}, count2[NO_OF_CHARS] = {0};
    int i;
    for (i = 0; str1[i] && str2[i]; i++) {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }
    if (str1[i] || str2[i]) return false;
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count1[i] != count2[i]) return false;
    return true;
}

int main() {
    char str1[] = "Geek";
    char str2[] = "for";
    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each other";
    return 0;
}
