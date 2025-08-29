/*
Question #12
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Remove All Spaces from a String.

My Answer:
✅ Output: Without spaces: Gfgtothemoon

Reason:
- Initialize an empty result string.
- Iterate through original string, append non-space chars to result.
- Print the result.

If Wrong:
Ensure all spaces (including multiple consecutive spaces) are removed.
*/

#include <iostream>
#include <string>
using namespace std;

string remove_spaces(string str) {
    string result = "";
    for (char c : str)
        if (c != ' ') result += c;
    return result;
}

int main() {
    string str = "Gfg to the moon";
    cout << "Without spaces: " << remove_spaces(str) << endl;
    return 0;
}
