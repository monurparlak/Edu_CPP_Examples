/*
Question #68
Source: CPP GeeksforGeeks

Question:
Write a C++ program to implement Linear Search on an array.

My Answer:
✅ Output: Element is present at index 5

Reason:
- Linear search checks each element of the array sequentially:
  1. Loop through array from index 0 to N-1.
  2. Compare each element with `x`.
  3. If found, return index.
  4. If end of array is reached without finding `x`, return -1.
- Works on both sorted and unsorted arrays.
*/

#include <iostream>
using namespace std;

int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int arr[] = { 5, 4, 1, 6, 10, 9, 23, 2 };
    int x = 9;
    int N = sizeof(arr) / sizeof(arr[0]);

    int result = search(arr, N, x);

    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;

    return 0;
}
