/*
Question #140
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 001

Reason:
- `int array[10];` → size = 10 * sizeof(int)
- `get_size_1(int* arr)`:
  - Parameter type is `int*` → array decays to pointer
  - sizeof(arr) = sizeof(int*) → likely smaller than sizeof(array)
  - Comparison: sizeof(array) == get_size_1(array) → false → 0

- `get_size_2(int arr[])`:
  - Parameter type `int arr[]` is equivalent to `int* arr` in function parameters
  - sizeof(arr) = sizeof(int*) → false → 0

- `get_size_3(int (&arr)[10])`:
  - Parameter is **reference to array of 10 ints**
  - sizeof(arr) = sizeof(int[10]) → equal to sizeof(array) → true → 1

- Therefore, printed: `0 0 1` → concatenated as **001**

If Wrong:
- Many expect `sizeof(arr)` inside a function to give array size, but **arrays decay to pointers** unless passed by reference.

Reference:
C++23 §7.3.7 — Array-to-pointer conversion in function parameters
*/

#include <iostream>
using namespace std;

size_t get_size_1(int* arr) { return sizeof arr; }
size_t get_size_2(int arr[]) { return sizeof arr; }
size_t get_size_3(int (&arr)[10]) { return sizeof arr; }

int main() {
    int array[10];
    cout << (sizeof(array) == get_size_1(array)); // 0
    cout << (sizeof(array) == get_size_2(array)); // 0
    cout << (sizeof(array) == get_size_3(array)); // 1
    // Output: 001
}
