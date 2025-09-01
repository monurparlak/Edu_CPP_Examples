/*
Question #125
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 121

Reason:
- `f` is a **function template**; each template instantiation gets its **own static variables**.
- Step by step:

1) `f(1);` → `T=int`  
   - `static int i=0;` → increment → 1  
   - Prints **1**

2) `f(1.0);` → `T=double`  
   - New instantiation, separate `i` → 0 → increment → 1  
   - Prints **1**

3) `f(1);` → `T=int`  
   - Same instantiation as first call → `i` was 1 → increment → 2  
   - Prints **2**

- Therefore, concatenated output: **121**

If Wrong:
- Some may think static variable is shared across all template types; in fact **each template specialization has its own static locals**.

Reference:
C++23 §13.5 — Template instantiation and function-local static variables
*/

#include <iostream>
using namespace std;

template <class T>
void f(T) {
    static int i = 0;
    cout << ++i;
}

int main() {
    f(1);    // prints 1 (T=int)
    f(1.0);  // prints 1 (T=double)
    f(1);    // prints 2 (T=int)
    // Output: 121
}
