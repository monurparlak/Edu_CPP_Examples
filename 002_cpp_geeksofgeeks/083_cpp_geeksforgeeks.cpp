/*
Question #83
Source: CPP GeeksforGeeks

Question:
Write a C++ program to sort the first half of an array in ascending order
and the second half in descending order.

My Answer:
✅ Output for input {1,2,3,4,5,6,7,8}:

1 2 3 4 8 7 6 5

Reason:
- Use two nested loops:
    - First loop sorts the first half (0 to n/2 - 1) ascending using bubble sort.
    - Second loop sorts the second half (n/2 to n-1) descending using bubble sort.
- After sorting, print the array in sequence.

If Wrong:
- Ensure you correctly separate the array into halves.
- Ensure the descending sort is applied only to the second half.
*/

#include <iostream>
using namespace std;

void ascDecFunc(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        // Ascending sort for first half
        for (int j = 0; j < n / 2 - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

        // Descending sort for second half
        for (int j = n / 2; j < n - 1; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    ascDecFunc(arr, len);

    return 0;
}
