/*
================================================================================
HackerRank C++ Challenge: Variable Sized Arrays - Array of Arrays
================================================================================

Objective:
----------
- This challenge teaches how to use **vectors of vectors** (dynamic arrays) in C++.
- You will read a set of variable-length arrays and answer queries for specific elements.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Vectors in C++:
   - Dynamic arrays that can grow/shrink at runtime.
   - Syntax:
       vector<int> v;             // empty vector of integers
       vector<int> v(n);          // vector of size n
       vector<vector<int>> vv;    // vector of vectors

2. Reading Variable-Length Arrays:
   - Use nested loops to read each sub-array into a vector.

3. Accessing Elements:
   - Use vv[i][j] to access the j-th element of the i-th sub-array.

4. Queries:
   - Each query specifies two indices (i, j):
       - i: index of sub-array
       - j: index within that sub-array
   - Print the element vv[i][j] for each query.

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- First line: two integers n (number of arrays) and q (number of queries)
- Next n lines: each line contains k followed by k space-separated integers (elements of array)
- Next q lines: each line contains i and j for queries

Example Input:
2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- For each query, print the element located at index j of array i on a new line

Example Output:
5
9
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q; // number of arrays and number of queries
    cin >> n >> q;

    // Step 1: Create a vector of vectors to hold variable-length arrays
    vector<vector<int>> arrays(n);

    // Step 2: Read each variable-length array
    for(int i = 0; i < n; i++) {
        int k; // size of current array
        cin >> k;
        arrays[i].resize(k); // resize current vector to hold k elements
        for(int j = 0; j < k; j++) {
            cin >> arrays[i][j];
        }
    }

    // Step 3: Process each query
    for(int i = 0; i < q; i++) {
        int arrayIndex, elementIndex;
        cin >> arrayIndex >> elementIndex;
        cout << arrays[arrayIndex][elementIndex] << endl;
    }

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Vectors are ideal for variable-length arrays in C++.
2. Use arrays[i].resize(k) to dynamically set the size of each sub-array.
3. Access elements using arrays[i][j] notation.
4. Queries are zero-based, ensure indices are correct.
5. This structure allows for flexible and memory-safe array manipulation.
================================================================================
*/
