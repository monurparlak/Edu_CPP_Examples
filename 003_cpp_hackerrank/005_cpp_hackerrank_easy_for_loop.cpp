/*
================================================================================
HackerRank C++ Challenge: For Loop - Conditional Printing
================================================================================

Objective:
----------
- This challenge teaches the use of a **for loop** to iterate over a range.
- You will increment a variable from a starting number to an ending number.
- Depending on the value, you will print:
    1. English words for numbers 1 to 9
    2. "even" for numbers greater than 9 that are even
    3. "odd" for numbers greater than 9 that are odd

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. For Loops in C++:
   - Syntax: 
       for (initialization; condition; update) {
           statement(s);
       }
   - expression_1: initialize loop control variable
   - expression_2: loop condition; stops loop when false
   - expression_3: update control variable each iteration
   - Example: for(int i = 0; i < 10; i++) { ... }

2. Conditional Statements:
   - if, else if, else
   - Used here to decide what to print for each number

3. Basic Input/Output:
   - cin to read input
   - cout to print output
   - endl to add newline

4. Arrays (optional, used for number-to-word mapping):
   - A string array can store the English words for numbers 1 to 9
   - Example:
       string nums[10] = {"zero", "one", "two", ..., "nine"};

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- Two positive integers, `a` and `b` (1 <= a <= b <= 100)
- Each integer on a new line

Example:
8
11

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- For each integer `i` in the inclusive interval [a, b]:
    - If 1 <= i <= 9: print English representation in lowercase ("one", "two", ...)
    - If i > 9 and even: print "even"
    - If i > 9 and odd: print "odd"

Example Output (for input above):
eight
nine
even
odd

--------------------------------------------------------------------------------
Step-by-Step Solution:
--------------------------------------------------------------------------------
1. Read the starting and ending integers `a` and `b` from input.
2. Create a string array with English words for 1-9.
3. Use a for loop to iterate from `a` to `b` inclusive.
4. Inside the loop:
    a. If i <= 9, print the English word from the array.
    b. Else if i > 9 and even, print "even".
    c. Else, print "odd".
*/

#include <iostream>
using namespace std;

int main() {
    // Step 1: Read input integers
    int a, b;
    cin >> a >> b;

    // Step 2: Array for numbers 1-9 in English
    string nums[10] = {"zero", "one", "two", "three", "four", 
                       "five", "six", "seven", "eight", "nine"};

    // Step 3: For loop from a to b inclusive
    for(int i = a; i <= b; i++) {
        // Step 4a: If number is between 1 and 9, print word
        if(i >= 1 && i <= 9) {
            cout << nums[i] << endl;
        }
        // Step 4b: If number > 9 and even
        else if(i > 9 && i % 2 == 0) {
            cout << "even" << endl;
        }
        // Step 4c: If number > 9 and odd
        else if(i > 9 && i % 2 != 0) {
            cout << "odd" << endl;
        }
    }

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Using an array makes mapping 1-9 to words very simple.
2. % operator checks for even/odd:
    - i % 2 == 0 → even
    - i % 2 != 0 → odd
3. The for loop ensures iteration over each integer in the inclusive range.
4. Make sure the output matches exactly; otherwise, HackerRank may mark wrong.
5. This template can be reused for other problems where loop + conditional logic is required.
================================================================================
*/
