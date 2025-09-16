/*
Question #81
Source: CPP GeeksforGeeks

Question:
Write a C++ program to check if an array is a subset of another array.

My Answer:
✅ Output for input:
arr1 = {1, 11, 31, 21, 30, 17}
arr2 = {11, 30, 17, 1}

Output: arr2 is subset of arr1

Reason:
- Iterate through each element of arr2.
- For each element, search in arr1.
- If any element of arr2 is not found in arr1, return false.
- Otherwise, return true.

If Wrong:
- Ensure the loop correctly checks all elements of arr2 in arr1.
- Be careful with array sizes m (arr1) and n (arr2).
*/

#include <iostream>
using namespace std;

bool isSubset(int arr1[], int arr2[], int m, int n) {
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
        if (j == m)
            return false;
    }
    return true;
}

int main() {
    int arr1[] = {1, 11, 31, 21, 30, 17};
    int arr2[] = {11, 30, 17, 1};

    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    if (isSubset(arr1, arr2, m, n))
        cout << "arr2 is subset of arr1 ";
    else
        cout << "arr2 is not a subset of arr1";

    return 0;
}
