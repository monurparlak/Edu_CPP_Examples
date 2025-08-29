/*
Question #107
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: fg

Reason:
- The call h({f(), g()}); uses list-initialization for a std::vector<int>.
- f() and g() are evaluated to provide the elements of the initializer list.
- In C++17 and later (including C++23), the order of evaluation of function
  arguments inside a braced-init-list is **strictly left-to-right**.
- Therefore, f() is called first (prints "f"), then g() is called (prints "g").
- The vector<int> v is constructed with elements {0, 0}, but only the
  side effects (printing "f" and "g") are visible.

If Wrong:
If you expected unspecified order, that was true before C++17.
C++17 introduced sequencing rules for initializer lists.

Reference:
C++23 §11.6.4.2 — Evaluation order in list-initialization
*/

#include <iostream>
#include <vector>
using namespace std;

int f() { cout << "f"; return 0; }
int g() { cout << "g"; return 0; }

void h(vector<int> v) {}

int main() {
    h({f(), g()}); // prints fg
    return 0;
}

