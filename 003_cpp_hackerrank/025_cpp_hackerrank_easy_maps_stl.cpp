/* ================================================================================
HackerRank C++ Challenge: Student Marks with Map
================================================================================

Objective:
----------
- Use a map to store total marks for each student.
- Handle three types of queries:
  1. Add marks to a student.
  2. Erase a student's record.
  3. Print a student's total marks (0 if student not found).

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- First line: q (number of queries)
- Next q lines: each line contains a query:
  * Type 1: "1 name marks" → add marks to student
  * Type 2: "2 name" → erase student
  * Type 3: "3 name" → print total marks

Output Format:
--------------------------------------------------------------------------------
- For each query of type 3, print the student's total marks or 0 if not present.

Example Input:
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess

Example Output:
30
20
0
================================================================================
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, int> marks;

    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            // Add marks to student
            string name;
            int score;
            cin >> name >> score;
            marks[name] += score; // automatically adds if not present
        } else if(type == 2) {
            // Erase student record
            string name;
            cin >> name;
            marks.erase(name);
        } else if(type == 3) {
            // Print total marks
            string name;
            cin >> name;
            if(marks.find(name) != marks.end()) {
                cout << marks[name] << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}

/* ================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. map<string,int> stores student names as keys and total marks as values.
2. marks[name] += score automatically initializes the value to 0 if name is new.
3. marks.erase(name) removes the student from the map.
4. marks.find(name) != marks.end() checks if the student exists.
5. Type 3 queries print 0 if the student has no record.
================================================================================
*/

