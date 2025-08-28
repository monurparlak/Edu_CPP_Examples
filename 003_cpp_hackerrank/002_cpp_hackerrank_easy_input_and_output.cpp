/*
================================================================================
HackerRank C++ Challenge: Sum of Three Numbers
================================================================================

Objective:
----------
- This challenge practices reading input from stdin and printing output to stdout.
- We will read three integers from a single line and print their sum.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Reading Input in C++:
   - Use `cin` to read whitespace-separated values.
   - Example:
       int a, b;
       cin >> a >> b;

2. Printing Output in C++:
   - Use `cout` to print values to stdout.
   - Separate values with spaces or other delimiters.
   - Use `endl` to add a newline at the end.

3. Sum Calculation:
   - Simply add the three integers and print the result.

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- One line containing three space-separated integers:
    a b c

Example:
1 2 7

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- Print the sum of the three integers on a single line.

Expected Output for Example Input:
10

--------------------------------------------------------------------------------
Step-by-Step Solution:
--------------------------------------------------------------------------------
1. Declare three integer variables.
2. Read input values using cin.
3. Calculate the sum of the three integers.
4. Print the sum using cout.
*/

#include <iostream>
using namespace std;

int main() {
    // Step 1: Declare variables
    int a, b, c;

    // Step 2: Read three integers from a single line
    cin >> a >> b >> c;

    // Step 3: Calculate sum
    int sum = a + b + c;

    // Step 4: Print the sum
    cout << sum << endl;

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. cin reads input token by token, separated by whitespace.
2. The order of reading matters; first token -> a, second -> b, third -> c.
3. cout prints the value followed by a newline using 'endl'.
4. This template can be extended for more numbers or more complex calculations.
================================================================================
*/
