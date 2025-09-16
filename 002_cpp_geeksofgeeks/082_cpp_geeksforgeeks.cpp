/*
Question #82
Source: CPP GeeksforGeeks

Question:
Write a C++ program to perform a circular rotation of an array
by K positions to the left.

My Answer:
✅ Output for input {1,2,3,4,5} and k=2:

3 4 5 1 2

Reason:
- Create a temporary array to hold rotated elements.
- Copy elements from index k to n-1 to the front of temp.
- Copy the first k elements to the end of temp.
- Copy temp back to the original array.
- Print the rotated array.

If Wrong:
- Ensure k is within the bounds 0 ≤ k < n.
- Ensure elements are copied in correct order.
*/

#include <iostream>
using namespace std;

void Rotate(int arr[], int k, int n) {
    int temp[n];
    int t = 0;

    // Copy elements from index k to n-1
    for (int i = k; i < n; i++) {
        temp[t++] = arr[i];
    }

    // Copy first k elements
    for (int i = 0; i < k; i++) {
        temp[t++] = arr[i];
    }

    // Copy temp back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    Rotate(arr, k, N);
    print_array(arr, N);

    return 0;
}
