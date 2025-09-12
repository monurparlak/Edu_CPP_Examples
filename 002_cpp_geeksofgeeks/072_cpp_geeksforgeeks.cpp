/*
Question #72
Source: CPP GeeksforGeeks

Question:
Write a C++ program to sort a given array in descending order.

My Answer:
✅ Output:
Array: 1 2 3 4 5 6 
Descending Sorted Array: 6 5 4 3 2 1

Reason:
- Approach:
  1. Use the STL `sort()` function.
  2. Pass the array begin and end pointers, and `greater<int>()` as comparator.
     This sorts the array in descending order.
  3. Print the array before and after sorting to verify.

If Wrong:
- Make sure to include `<functional>` if using `greater<int>()` explicitly.
- Do not forget to pass the correct array size.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    sort(arr, arr + n, greater<int>());

    cout << "\nDescending Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
