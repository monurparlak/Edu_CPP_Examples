/*
================================================================================
HackerRank C++ Challenge: Functions - Maximum of Four Numbers
================================================================================

Objective:
----------
- This challenge teaches how to define and use functions in C++.
- You will write a function `max_of_four` that returns the maximum of four integers.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Functions in C++:
   - Functions are reusable blocks of code that take zero or more arguments.
   - Syntax:
       return_type function_name(arg_type1 arg1, arg_type2 arg2, ...) {
           // code
           return value; // if return_type is not void
       }

2. Function Return Types:
   - void: function does not return anything
   - Non-void: function must return a value of specified type

3. Arithmetic and Comparison:
   - Use if-else or conditional operators to compare values
   - Example: `if(a > b) max = a; else max = b;`

4. Operators:
   - `+=` adds the right-hand value to the left-hand variable:
       a += b is equivalent to a = a + b

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- Four integers, each on a separate line:
    a
    b
    c
    d

Constraints:
- Typical integer range (-2^31 to 2^31 - 1)

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- Return the greatest of the four integers.

Example Input:
3
4
6
5

Example Output:
6
*/

#include <iostream>
using namespace std;

// Function to return the maximum of four integers
int max_of_four(int a, int b, int c, int d) {
    int max_val = a; // assume a is maximum initially

    // Compare with b
    if(b > max_val) {
        max_val = b;
    }
    // Compare with c
    if(c > max_val) {
        max_val = c;
    }
    // Compare with d
    if(d > max_val) {
        max_val = d;
    }

    return max_val; // return the largest value
}

int main() {
    // Input four integers
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Call function and print the result
    cout << max_of_four(a, b, c, d) << endl;

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Functions improve code readability and reusability.
2. You can also use nested max() calls:
       return max(max(a,b), max(c,d));
3. Ensure your function returns the correct type (int in this case).
4. Test with negative and equal numbers to confirm correctness.
================================================================================
*/
