/*
================================================================================
HackerRank C++ Challenge: C++ Data Types - Reading and Printing
================================================================================

Objective:
----------
- This challenge teaches reading and printing different C++ data types.
- You will work with: int, long, char, float, and double.
- You will practice using both:
    1. scanf/printf (C-style)
    2. cin/cout (C++ style, optional)

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Common C++ Data Types:
   - int: 32-bit integer
   - long: 64-bit integer
   - char: single character
   - float: 32-bit floating point
   - double: 64-bit floating point

2. Reading Input:
   - scanf(format, &variable) for C-style input
       Example: scanf("%d %ld %c %f %lf", &i, &l, &c, &f, &d);
   - cin >> variable for C++ style

3. Printing Output:
   - printf(format, variable) for C-style
       - Use "%.3f" for 3 decimal float precision
       - Use "%.9lf" for 9 decimal double precision
   - cout << fixed << setprecision(n) << variable for C++ style

4. Floating Point Precision:
   - float: print up to 3 decimal places
   - double: print up to 9 decimal places

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- Five space-separated values in one line:
    int_value long_value char_value float_value double_value

Example:
3 12345678912345 a 334.23 14049.30493

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- Print each value on a new line in the same order.
- Floating point values must follow required precision.

Expected Output for Example Input:
3
12345678912345
a
334.230
14049.304930000

--------------------------------------------------------------------------------
Step-by-Step Solution:
--------------------------------------------------------------------------------
1. Declare variables for each data type.
2. Read input using scanf or cin.
3. Print each variable in order:
    - int and long: direct print
    - char: direct print
    - float: 3 decimal places
    - double: 9 decimal places
4. Ensure each output is on a new line.
*/

#include <iostream>
#include <cstdio>   // For printf and scanf
#include <iomanip>  // For cout precision (optional)
using namespace std;

int main() {
    // Step 1: Declare variables
    int i;
    long l;
    char c;
    float f;
    double d;

    // Step 2: Read input (C-style)
    scanf("%d %ld %c %f %lf", &i, &l, &c, &f, &d);

    // Step 3: Print each value on a new line
    printf("%d\n", i);               // int
    printf("%ld\n", l);              // long
    printf("%c\n", c);               // char
    printf("%.3f\n", f);             // float with 3 decimals
    printf("%.9lf\n", d);            // double with 9 decimals

    /*
    // Optional: Using C++ style
    cout << i << endl;
    cout << l << endl;
    cout << c << endl;
    cout << fixed << setprecision(3) << f << endl;
    cout << fixed << setprecision(9) << d << endl;
    */

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Use & in scanf to pass variable addresses.
2. For float precision in printf: %.3f
3. For double precision in printf: %.9lf
4. C++ cin/cout is easier but slower for large inputs.
5. Always print each value on a new line.
================================================================================
*/
