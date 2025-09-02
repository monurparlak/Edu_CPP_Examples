/*
================================================================================
HackerRank C++ Challenge: Pointers - Update Function
================================================================================

Objective:
----------
- This challenge teaches how to use **pointers** to modify variables via memory addresses.
- You will complete a function `update` that modifies two integers:
    1. a becomes the sum of the two numbers
    2. b becomes the absolute difference of the two numbers

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Pointers in C++:
   - A pointer stores the memory address of another variable.
   - Syntax: int *p; // pointer to an integer
   - Access the address: &variable
   - Access or modify the value: *pointer

2. Passing by Reference Using Pointers:
   - Functions can modify the original variable if passed as a pointer.
   - Example:
       void increment(int *v) { (*v)++; }

3. Absolute Value:
   - abs(x) returns the absolute value of integer x
   - Can be used to ensure difference is positive

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- Two integers, a and b, separated by newline

Example Input:
4
5

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- First line: sum of a and b
- Second line: absolute difference of a and b

Example Output:
9
1
*/

#include <iostream>
#include <cmath> // for abs()
using namespace std;

// Function to update two integers via pointers
void update(int *a, int *b) {
    int sum = *a + *b;        // dereference pointers to access values
    int diff = abs(*a - *b);  // calculate absolute difference
    *a = sum;                  // store sum in the memory pointed by a
    *b = diff;                 // store absolute difference in the memory pointed by b
}

int main() {
    int a, b;

    // Read input values
    cin >> a >> b;

    // Call update function with pointers to a and b
    update(&a, &b);

    // Print updated values
    cout << a << endl; // sum
    cout << b << endl; // absolute difference

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Pointers allow functions to modify variables outside their scope.
2. Always dereference the pointer using * to access or modify the value.
3. Use abs() for absolute value to ensure positive difference.
4. Function declared as void does not return a value; changes happen in memory.
5. Test with a < b, a > b, and a == b to verify correctness.
================================================================================
*/
