/*
================================================================================
HackerRank C++ Challenge: String Manipulation
================================================================================

Objective:
----------
- Learn to use the C++ string class for basic operations.
- Demonstrate string length, concatenation, and character swapping.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Declaration and Initialization:
   string a = "abc";

2. Size / Length:
   int len = a.size(); // returns the length of string

3. Concatenation:
   string c = a + b;

4. Accessing / Modifying Elements:
   char ch = s[0]; // access first character
   s[0] = 'z';     // modify first character

5. Input / Output:
   cin >> str;
   cout << str << endl;

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- Two strings, each on a new line, consisting of lowercase letters.

Example Input:
abcd
ef

Expected Output:
4 2
abcdef
ebcd af
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b; // read two strings

    // Print lengths of the strings
    cout << a.size() << " " << b.size() << endl;

    // Print concatenation of strings
    cout << a + b << endl;

    // Swap first characters of a and b
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    // Print the strings after swapping first characters
    cout << a << " " << b << endl;

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Use string.size() to get length of string.
2. Use the + operator to concatenate strings.
3. Strings are mutable; you can assign to individual characters.
4. Remember that strings are 0-indexed in C++.
================================================================================
*/
