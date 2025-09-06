/*
================================================================================
HackerRank C++ Challenge: String Streams - Parse Comma-Separated Integers
================================================================================

Objective:
----------
- Learn to use stringstream for parsing strings in C++.
- Extract integers from a comma-separated string.
- Store parsed integers in a vector.
- Understand the use of `>>` operator and temporary variables for delimiters.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. stringstream:
   - `stringstream ss(str);` initializes a stream with a string.
   - `ss >> variable` extracts formatted data (e.g., integers).
   - `ss >> ch` can be used to discard delimiters like commas.

2. Vectors:
   - `vector<int>` can store a dynamic list of integers.
   - Use `push_back()` to add elements to the vector.

3. Parsing Technique:
   - Read integer
   - Skip delimiter (comma)
   - Repeat until the end of the string

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- A single line containing integers separated by commas.

Example Input:
23,4,56

Expected Output:
23
4
56
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Function to parse comma-separated integers
vector<int> parseInts(string str) {
    vector<int> result;
    stringstream ss(str);
    int number;
    char comma;

    // Extract numbers separated by commas
    while (ss >> number) {
        result.push_back(number);
        ss >> comma; // discard the comma
    }

    return result;
}

int main() {
    string input;
    cin >> input;

    vector<int> integers = parseInts(input);

    // Print each integer on a new line
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << endl;
    }

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Use stringstream to conveniently parse formatted data from strings.
2. Always discard delimiters like commas when parsing.
3. Vectors allow dynamic storage of elements when the number of integers is unknown.
4. This technique can be extended to parse other delimiter-separated values (e.g., spaces, semicolons).
================================================================================
*/
