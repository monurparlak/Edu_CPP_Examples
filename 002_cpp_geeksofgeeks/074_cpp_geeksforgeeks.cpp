/*
Question #74
Source: CPP GeeksforGeeks

Question:
Write a C++ program to find the k maximum elements
from a given array.

My Answer:
✅ Output:
84 50 45

Reason:
- Approach:
  1. Copy original array `arr` into `c` for printing later.
  2. Initialize `result` array to mark positions of k max elements.
  3. Loop k times:
     - Find the maximum element in the current `arr`.
     - Record its index in `result`.
     - Replace that element in `arr` with INT_MIN so it is not selected again.
  4. Print elements of `c` where `result[i] == 1`.
- For the array {50, 8, 45, 12, 25, 40, 84} and k = 3:
  Maximum elements are 84, 50, and 45.

If Wrong:
- Avoid modifying original array directly if you need it later.
- Ensure proper marking and printing using the auxiliary `result` array.
*/

#include <bits/stdc++.h>
using namespace std;

void printMax(int arr[], int n, int k)
{
    int result[n], c[n];

    for (int i = 0; i < n; i++) {
        c[i] = arr[i];
        result[i] = 0;
    }

    for (int i = 0; i < k; i++) {
        int maxi = INT_MIN;
        int index;
        for (int j = 0; j < n; j++) {
            if (arr[j] > maxi) {
                maxi = arr[j];
                index = j;
            }
        }
        result[index] = 1;
        arr[index] = INT_MIN;
    }

    for (int i = 0; i < n; i++) {
        if (result[i] == 1)
            cout << c[i] << " ";
    }
}

int main()
{
    int arr[] = { 50, 8, 45, 12, 25, 40, 84 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printMax(arr, n, k);
    return 0;
}
