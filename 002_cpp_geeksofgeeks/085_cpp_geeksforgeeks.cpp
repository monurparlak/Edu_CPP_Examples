/*
Question #85
Source: CPP GeeksforGeeks

Question:
Write a C++ program to print all permutations of a given string using recursion.

My Answer:
✅ Output for input "ABC":

ABC
ACB
BAC
BCA
CAB
CBA

Reason:
- Use recursion by fixing each character at current position and permuting the remaining substring.
- Base case: when input string is empty, print the accumulated answer.
- For each recursive call:
    - Remove the character at current index.
    - Append it to the accumulated answer.
    - Recurse on the remaining string.

If Wrong:
- Make sure to correctly form the remaining substring after removing the chosen character.
- Ensure that all recursive branches are covered.
*/

#include <iostream>
#include <string>
using namespace std;

void permute(string s, string answer) {
    if (s.length() == 0) {
        cout << answer << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        string result = left + right;
        permute(result, answer + ch);
    }
}

int main() {
    string s = "ABC";
    string answer = "";
    permute(s, answer);
    return 0;
}
