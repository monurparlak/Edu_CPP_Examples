/*
Question #66
Source: CPP GeeksforGeeks

Question:
Write a C++ program to implement MergeSort algorithm on an array.

My Answer:
✅ Output:
Array: 5 6 3 10 1 4 9
Sorted array: 1 3 4 5 6 9 10

Reason:
- MergeSort works using divide-and-conquer:
  1. Recursively divide the array into halves until size 1.
  2. Merge the halves in sorted order using a temporary array.
- Complexity: O(n log n) in all cases.
- Space complexity: O(n) due to temporary arrays.
*/

#include <iostream>
using namespace std;

// Merge two sorted subarrays
void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// MergeSort function
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Print array
void print_array(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    int arr[] = { 5, 6, 3, 10, 1, 4, 9 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    print_array(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array: ";
    print_array(arr, arr_size);
    return 0;
}
