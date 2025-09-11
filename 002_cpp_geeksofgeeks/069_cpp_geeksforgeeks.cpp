/*
Question #69
Source: CPP GeeksforGeeks

Question:
Write a C++ program to implement Binary Search on a sorted array.

My Answer:
✅ Output: Element is present at index 4

Reason:
- Binary search works on sorted arrays by repeatedly dividing the search interval in half:
  1. Compute middle element: `mid = l + (r - l) / 2`
  2. If `arr[mid] == x`, return `mid`.
  3. If `arr[mid] > x`, search in left half.
  4. If `arr[mid] < x`, search in right half.
  5. If the search interval is empty, return -1.
- The array must be sorted for binary search to work correctly.
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int x = 5;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;

    return 0;
}
