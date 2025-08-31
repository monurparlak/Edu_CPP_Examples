/*
Question #25
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Calculate the Sum of Elements in an Array.

My Answer:
✅ Output: Sum: 99

Reason:
- Initialize sum = 0.
- Loop through array elements, add each to sum.
- Print sum after loop ends.

If Wrong:
Ensure array size n is correctly computed and all elements are summed.
*/

#include <iostream>
using namespace std;

int sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

int main() {
    int arr[] = {1, 23, 54, 12, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Sum: " << sum(arr, n) << endl;
    return 0;
}
