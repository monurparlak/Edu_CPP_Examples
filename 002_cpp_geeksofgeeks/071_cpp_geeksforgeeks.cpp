/*
Question #71
Source: CPP GeeksforGeeks

Question:
Write a C++ program to remove duplicate elements from an array using STL.

My Answer:
✅ Output:
Before removing duplicates:
1 2 2 4 3 3 2 1 
After removing duplicates:
1 2 3 4

Reason:
- Approach:
  1. Use a `set<int>` to store unique elements from the array.
  2. Insert each element of the array into the set.
  3. Iterate through the set to print the unique elements (duplicates are removed automatically).
  4. Sets in C++ automatically maintain ascending order.

If Wrong:
- Make sure to include `<set>` header or `<bits/stdc++.h>`.
- Remember that `set` will sort elements in ascending order; for original order, use `unordered_set`.
*/

#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(int arr[], int n)
{
    set<int> s;

    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    cout << "\nAfter removing duplicates:\n";
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << '\n';
}

int main()
{
    int arr[] = { 1, 2, 2, 4, 3, 3, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nBefore removing duplicates:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    removeDuplicates(arr, n);

    return 0;
}
