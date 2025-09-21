/* ================================================================================
HackerRank C++ Challenge: Set Queries
================================================================================

Objective:
----------
- Use a set to store unique integers.
- Handle three types of queries:
  1. Add x to the set.
  2. Delete x from the set.
  3. Check if x is present; print "Yes" or "No".

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- First line: q (number of queries)
- Next q lines: each line has two integers: type x
  * type = 1 → insert x
  * type = 2 → erase x
  * type = 3 → check x

Output Format:
--------------------------------------------------------------------------------
- For each query of type 3, print "Yes" if x is in the set, "No" otherwise.

Example Input:
8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Example Output:
Yes
No
No
================================================================================
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> s;

    for(int i = 0; i < q; i++) {
        int type, x;
        cin >> type >> x;

        if(type == 1) {
            // Insert x into set
            s.insert(x);
        } else if(type == 2) {
            // Erase x from set (does nothing if x not present)
            s.erase(x);
        } else if(type == 3) {
            // Check if x is present
            if(s.find(x) != s.end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}

/* ================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. set<int> automatically stores elements in sorted order and ensures uniqueness.
2. s.insert(x) → adds x if not present.
3. s.erase(x) → removes x if present.
4. s.find(x) → returns iterator to x if present, else s.end().
5. Type 3 queries simply check presence using s.find().
================================================================================
*/

