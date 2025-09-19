/* ================================================================================
HackerRank C++ Challenge: Vector Erase Operations
================================================================================

Objective:
----------
- Read a vector of integers.
- Perform two erase operations:
  1. Remove an element at a given position.
  2. Remove a range of elements from position a to b-1.
- Print the final size and elements of the vector.

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- First line: n (number of integers in the vector)
- Second line: n space-separated integers
- Third line: x (position to remove, 1-based index)
- Fourth line: a b (range of positions to remove, 1-based, remove a to b-1)

Output Format:
--------------------------------------------------------------------------------
- First line: size of vector after erase operations
- Second line: remaining elements separated by space

Example Input:
6
1 4 6 2 8 9
2
2 4

Example Output:
3
1 8 9
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    // Read n integers into the vector
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    int x; // first erase position (1-based)
    cin >> x;

    int a, b; // range to erase (1-based)
    cin >> a >> b;

    // 1. Erase the element at position x (convert 1-based to 0-based)
    v.erase(v.begin() + (x - 1));

    // 2. Erase the range from a to b-1 (convert to 0-based)
    v.erase(v.begin() + (a - 1), v.begin() + (b - 1));

    // Print final size
    cout << v.size() << endl;

    // Print remaining elements
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

/* ================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. v.erase(v.begin() + index) removes a single element at index.
2. v.erase(v.begin() + start, v.begin() + end) removes elements from start to end-1.
3. Convert 1-based input positions to 0-based for vector operations.
================================================================================
*/

