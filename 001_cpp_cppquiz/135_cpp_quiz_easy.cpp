/*
Question #135
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 210

Reason:
- `std::map` stores **unique keys**.
- `std::map<bool,int> mb = {{1,2},{3,4},{5,0}};`
  - Keys: 1, 3, 5 → all converted to `bool`:
    - 1 → true
    - 3 → true
    - 5 → true
  - Only **one true key exists** in `mb`
  - So `mb.size()` → 1

- `std::map<int,int> mi = {{1,2},{3,4},{5,0}};`
  - Keys: 1, 3, 5 → all unique as int
  - So `mi.size()` → 3

- Therefore, concatenated output: **1 3**

If Wrong:
- Common mistake: forget that `bool` map converts all non-zero integers to `true`, collapsing multiple entries.

Reference:
C++23 §23.4.4.3 — Associative container key uniqueness rules
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<bool,int> mb = {{1,2},{3,4},{5,0}};
    cout << mb.size(); // 1

    map<int,int> mi = {{1,2},{3,4},{5,0}};
    cout << mi.size(); // 3
    // Output: 13
}
