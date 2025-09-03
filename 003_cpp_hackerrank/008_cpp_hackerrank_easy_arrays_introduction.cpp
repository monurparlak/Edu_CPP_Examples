/*
================================================================================
HackerRank C++ Challenge: Arrays - Reverse Print
================================================================================

Objective:
----------
- This challenge teaches how to use **arrays** in C++.
- You will read an array of integers and print them in reverse order.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Arrays in C++:
   - Contiguous block of memory storing elements of the same type.
   - Declared with a fixed or dynamic size:
       int arr[10];       // array of 10 integers
       int arr[n];        // array of size n (C++ allows runtime size)
   - Access elements using indices starting from 0:
       arr[0] is the first element
       arr[1] is the second, etc.

2. Reading Input into an Array:
   - Use a loop to read elements:
       for(int i = 0; i < n; i++) cin >> arr[i];

3. Printing Array in Reverse:
   - Start from the last index and move to the first:
       for(int i = n-1; i >= 0; i--) cout << arr[i] << " ";

4. Space Separation:
   - Use `" "` between elements when printing.
   - Optional: avoid trailing space by conditionally printing space or using a separate approach.

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- First line: integer n (size of array)
- Second line: n space-separated integers

Example Input:
4
1 4 3 2

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- Print the array elements in reverse order, space-separated, on a single line

Expected Output for Example Input:
2 3 4 1
*/

#include <iostream>
using namespace std;

int main() {
    // Step 1: Read array size
    int n;
    cin >> n;

    // Step 2: Declare array of size n
    int arr[n];

    // Step 3: Read n integers into array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 4: Print array in reverse order
    for(int i = n - 1; i >= 0; i--) {
        cout << arr[i];
        if(i > 0) cout << " "; // Add space between elements but not after last element
    }
    cout << endl;

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Arrays in C++ are zero-indexed.
2. Loop backwards using i = n-1 down to i = 0 for reverse printing.
3. Use conditional spacing to avoid extra space at the end.
4. For very large arrays, consider using vectors instead of fixed-size arrays.
5. This problem reinforces basic array manipulation and loop control.
================================================================================
*/
