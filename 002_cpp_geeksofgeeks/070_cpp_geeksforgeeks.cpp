/*
Question #70
Source: CPP GeeksforGeeks

Question:
Write a C++ program to find the index of an element in a vector.

My Answer:
✅ Output: 4

Reason:
- Approach:
  1. Use `std::find` from `<algorithm>` to search for the element in the vector.
  2. If the element is found, `std::find` returns an iterator pointing to it.
  3. Subtract `v.begin()` from the iterator to get the index.
  4. If the element is not found, `std::find` returns `v.end()`; print `-1` in that case.

If Wrong:
- Make sure to include `<algorithm>` header.
- Remember that vector indices are 0-based.
*/

#include <bits/stdc++.h>
using namespace std;

void print_index(vector<int> v, int element)
{
    auto it = find(v.begin(), v.end(), element);

    if (it != v.end()) {
        int index = it - v.begin();
        cout << index << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6 };
    int element = 5;

    print_index(v, element);

    return 0;
}
