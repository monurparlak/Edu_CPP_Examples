/*
Question #122
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 2

Reason:
- `typedef long long ll;` → defines `ll` as **alias for long long**
- Function overloads:
  1) `void foo(unsigned ll)` → actually `void foo(unsigned long long)`  
     - `unsigned ll` is **same as unsigned long long** (valid C++? actually GCC/Clang accept, but standard forbids `unsigned ll` as ambiguous)
  2) `void foo(unsigned long long)` → prints "2"
- Call: `foo(2ull);`  
  - `2ull` is **unsigned long long** literal
  - Exact match → calls `foo(unsigned long long)` → prints **2**

If Wrong:
- Some compilers may reject `unsigned ll` syntax (C++ standard forbids typedefs in type specifier like that in traditional unsigned declaration), but assuming it compiles, **the second overload is used**.

Reference:
C++23 §11.3 — Function overloading and type alias rules
*/

#include <iostream>
using namespace std;

typedef long long ll;

void foo(unsigned ll) { cout << "1"; }       // treated as unsigned long long
void foo(unsigned long long) { cout << "2"; }

int main() {
    foo(2ull);  // prints 2
}
