/*
Question #64
Source: CPP GeeksforGeeks

Question:
Write a C++ program to sort an array using Insertion Sort algorithm.

My Answer:
✅ Output:
Sorted array: 1 2 3 4 5

Reason:
- Insertion sort builds the sorted array one element at a time by placing each element in its correct position relative to the already sorted part.
- Best case: O(n) if array is already sorted.
- Worst/average case: O(n^2).
- Space Complexity: O(1), in-place sorting.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to sort using Insertion Sort
void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Print array
void print_array(int arr[], int n)
{
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 1, 4, 3, 2, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, N);
    print_array(arr, N);

    return 0;
}
