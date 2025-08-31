/*
Question #23
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Find the Minimum and Maximum Elements of an Array.

My Answer:
✅ Output:
Min: 1
Max: 5

Reason:
- Initialize mini and maxi as first array element.
- Traverse the array, update mini if smaller, maxi if larger.
- Print mini and maxi after the loop.

If Wrong:
Ensure all array elements are compared and initial values are correct.
*/

#include <iostream>
using namespace std;

void findMinMax(int arr[], int n) {
    int mini = arr[0], maxi = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < mini) mini = arr[i];
        else if (arr[i] > maxi) maxi = arr[i];
    }
    cout << "Min: " << mini << endl;
    cout << "Max: " << maxi << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int N = sizeof(arr)/sizeof(arr[0]);
    findMinMax(arr, N);
    return 0;
}
