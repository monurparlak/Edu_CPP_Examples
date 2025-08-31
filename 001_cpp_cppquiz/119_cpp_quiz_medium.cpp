/*
Question #119
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 1

Reason:
- In 'void* p = &p;', p is defined as a void pointer.
- '&p' takes the address of the variable p itself (i.e., p points to its own
  storage).
- This is valid in C++: a pointer variable can hold the address of itself.
- The result is a non-null pointer value (since every object in main has an
  address).
- In std::cout << bool(p); the pointer is converted to bool:
  - Non-null pointer → true → printed as '1'.
- Therefore, the program prints 1.

If Wrong:
If you expected 0, that would require p to be initialized with nullptr,
not with its own address.

Reference:
C++23 §7.3.14 — Pointer to object and boolean conversion rules
*/

#include <iostream>
using namespace std;

int main() {
    void* p = &p;   // p holds its own address
    cout << bool(p); // prints 1
    return 0;
}
