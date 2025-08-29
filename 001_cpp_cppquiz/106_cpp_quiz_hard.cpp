/*
Question #106
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: undefined behavior

Reason:
- The declaration 'extern "C" int x;' declares x as an object with external
  linkage, but does not define or initialize it.
- The block 'extern "C" { int y; }' is a definition of y with external
  linkage. Since it has static storage duration and no initializer, it is
  zero-initialized (so y = 0).
- However, 'x' is only declared, not defined anywhere in the program. 
  Using 'x' in main() leads to an **ODR violation / undefined behavior**.
- If the linker does not complain (non-conforming), reading 'x' has no
  defined value.

If Wrong:
To make the program well-formed and defined, provide a definition for x:
    extern "C" int x = 0;

Reference:
C++23 §6.9.3.2 — Zero-initialization of static storage duration objects  
C++23 §6.2/6 — One Definition Rule (ODR)
*/

// C++ Program demonstrating extern "C" linkage and ODR
#include <iostream>
using namespace std;

extern "C" int x;   // declaration only, no definition
extern "C" { int y; } // definition, zero-initialized

int main() {
    cout << x << y; // UB: 'x' is not defined
    return 0;
}

