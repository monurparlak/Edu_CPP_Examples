/*
Question #65
Source: CPP GeeksforGeeks

Question:
Write a C++ program to sort an array using Selection Sort algorithm.

My Answer:
✅ Output:
Sorted array: 1 2 3 4 5

Reason:
- Selection sort repeatedly selects the minimum element from the unsorted part of the array and swaps it with the first unsorted element.
- Time Complexity: O(n^2) in all cases.
- Space Complexity: O(1), in-place sorting.
*/

#include <iostream>
using namespace std;

// Swap function
void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    int min_index;

    for (int i = 0; i < n - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        if (min_index != i)
            swap(&arr[min_index], &arr[i]);
    }
}

// Print Array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 5, 4, 3, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
