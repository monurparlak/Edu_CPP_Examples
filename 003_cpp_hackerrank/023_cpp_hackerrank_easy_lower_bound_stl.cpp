/* ================================================================================
HackerRank C++ Challenge: Lower Bound Queries
================================================================================

Objective:
----------
- Given a sorted vector of integers, answer multiple queries:
  1. If the query integer is present, print "Yes" and its 1-based index (first occurrence).
  2. If not present, print "No" and the 1-based index of the smallest integer greater than the query.

Concepts Covered:
-----------------
- std::vector
- std::lower_bound
- Iterator arithmetic

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- First line: n (number of integers in the array)
- Second line: n sorted integers
- Third line: q (number of queries)
- Next q lines: one integer per query

Output Format:
--------------------------------------------------------------------------------
- For each query, print "Yes" or "No" followed by the 1-based index as described.

Example Input:
8
1 1 2 2 6 9 9 15
4
1
4
9
15

Example Output:
Yes 1
No 5
Yes 6
Yes 8
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    // Read sorted array
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int q;
    cin >> q;

    // Process queries
    for(int i = 0; i < q; i++) {
        int query;
        cin >> query;

        // Use lower_bound to find the first element >= query
        auto it = lower_bound(v.begin(), v.end(), query);

        if(it != v.end() && *it == query) {
            // Found: print "Yes" and 1-based index
            cout << "Yes " << (it - v.begin() + 1) << endl;
        } else {
            // Not found: print "No" and 1-based index of next greater element
            cout << "No " << (it - v.begin() + 1) << endl;
        }
    }

    return 0;
}

/* ================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. lower_bound returns an iterator to the first element >= target in a sorted vector.
2. Subtracting v.begin() from the iterator gives 0-based index.
3. Add 1 to convert to 1-based index as required by the problem.
4. Works correctly even if the query number is not in the array.
================================================================================
*/

