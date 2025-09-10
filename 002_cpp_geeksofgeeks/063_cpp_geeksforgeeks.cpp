/*
Question #63
Source: CPP GeeksforGeeks

Question:
Write a C++ program to sort an array using Bubble Sort algorithm.

My Answer:
✅ Output:
Sorted array: 1 2 3 4 5

Reason:
- Bubble sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
- Best case: O(n) if the array is already sorted (optimized with a flag).
- Worst/average case: O(n^2).
- Space Complexity: O(1), in-place sorting.
*/

#include <iostream>
using namespace std;

// Function to sort using Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 3, 1, 4, 2, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, N);

    cout << "Sorted array: ";
    printArray(arr, N);
    return 0;
}
