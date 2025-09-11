/*
Question #67
Source: CPP GeeksforGeeks

Question:
Write a C++ program to implement QuickSort algorithm on an array.

My Answer:
✅ Output:
Array: 2 5 6 9 1 3 4
Sorted array: 1 2 3 4 5 6 9

Reason:
- QuickSort works using divide-and-conquer:
  1. Select a pivot (here, last element).
  2. Partition array: elements smaller than pivot left, larger right.
  3. Recursively sort left and right subarrays.
- Partition function moves pivot to correct sorted position.
- Complexity: O(n log n) average, O(n^2) worst case.
*/

#include <iostream>
using namespace std;

// Swap  elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function to find pivot position
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 2, 5, 6, 9, 1, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
