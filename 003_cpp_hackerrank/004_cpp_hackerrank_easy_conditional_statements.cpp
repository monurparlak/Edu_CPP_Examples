/*
================================================================================
HackerRank C++ Challenge: If-Else - Print Number as Word or "Greater than 9"
================================================================================

Objective:
----------
- This challenge teaches how to use **if, else if, else** statements.
- Depending on the value of a positive integer 'n':
    1. If 1 <= n <= 9, print the corresponding English word in lowercase.
    2. If n > 9, print "Greater than 9".

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Conditional Statements in C++:
   - if: Executes code block only if condition is true.
       Syntax:
           if(condition) {
               // statements
           }

   - if-else: Executes one of two code blocks depending on a condition.
       Syntax:
           if(condition) {
               // statements if true
           } else {
               // statements if false
           }

   - if-else if-else: Chains multiple conditions, only the first true condition executes.
       Syntax:
           if(condition1) {
               // statements
           } else if(condition2) {
               // statements
           } else {
               // statements if all false
           }

2. Input/Output:
   - cin for reading input
   - cout for printing output
   - endl for newline

3. Arrays (optional):
   - An array can store English words for numbers 1 to 9.
   - Example: string nums[10] = {"zero", "one", "two", ..., "nine"};

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- A single positive integer, n.

Constraints:
------------
- 1 <= n <= 100 (or positive integer)

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- If 1 <= n <= 9: print the corresponding English word.
- Else: print "Greater than 9".

--------------------------------------------------------------------------------
Sample Input/Output:
--------------------------------------------------------------------------------
Input: 5
Output: five

Input: 8
Output: eight

Input: 44
Output: Greater than 9

--------------------------------------------------------------------------------
Step-by-Step Solution:
--------------------------------------------------------------------------------
1. Read integer n from input.
2. Check if n is between 1 and 9:
    a. If yes, print the English word using an array or if-else chain.
3. Otherwise, print "Greater than 9".
*/

#include <iostream>
using namespace std;

int main() {
    // Step 1: Read input
    int n;
    cin >> n;

    // Step 2: Array of English words for 1-9
    string nums[10] = {"zero", "one", "two", "three", "four",
                       "five", "six", "seven", "eight", "nine"};

    // Step 3: Conditional logic using if-else
    if(n >= 1 && n <= 9) {
        // Print the corresponding word
        cout << nums[n] << endl;
    } else {
        // n is greater than 9
        cout << "Greater than 9" << endl;
    }

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Using an array simplifies mapping numbers to words.
2. If you prefer, you can also use a series of if-else statements:
       if(n == 1) cout << "one";
       else if(n == 2) cout << "two";
       ...
       else cout << "Greater than 9";
3. Make sure the output exactly matches the required string.
4. Remember to include 'endl' to move to the next line.
5. This is a good practice problem for understanding conditional logic in C++.
================================================================================
*/
