/* ================================================================================
HackerRank C++ Challenge: Vector Sorting
================================================================================

Objective:
----------
- Read a sequence of integers.
- Store them in a vector.
- Sort the vector in ascending order.
- Print the sorted integers in a single line separated by spaces.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Vectors in C++:
   - Dynamic arrays that can change size.
   - Use v.push_back(x) to add elements.
   - Use v.size() to get the current number of elements.

2. Sorting:
   - Use sort(v.begin(), v.end()) to sort all elements.

3. Input/Output:
   - Read integers using cin.
   - Print integers using cout.

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- First line: n (number of integers)
- Second line: n space-separated integers

Output Format:
--------------------------------------------------------------------------------
- Print sorted integers in ascending order in a single line separated by spaces.

Example Input:
5
1 6 10 8 4

Example Output:
1 4 6 8 10
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v; // Create an empty vector of integers

    // Read integers and store in the vector
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // Sort the vector in ascending order
    sort(v.begin(), v.end());

    // Print sorted integers
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

/* ================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. vector<int> v; creates a dynamic array that can grow with push_back().
2. sort(v.begin(), v.end()) sorts the vector in ascending order.
3. Access elements using v[i] for printing.
4. This solution works for any valid input of n integers.
================================================================================
*/

