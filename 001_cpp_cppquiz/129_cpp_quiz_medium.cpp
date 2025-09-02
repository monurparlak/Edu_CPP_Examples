/*
Question #129
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
❌ Output: Compilation error

Reason:
- `std::vector<char> delimiters = { ",", ";" };`
  - `","` and `";"` are **string literals** → type `const char[2]`
  - `std::vector<char>` expects **single characters**, not strings
  - The initializer list `{",", ";"}` cannot be converted to `char`
- Compiler will emit **type mismatch error**.
- `delimiters[0]` cannot exist because `delimiters` fails to compile.

If Wrong:
- To fix, use single quotes for characters:  
  `std::vector<char> delimiters = { ',', ';' };`
  - Then `delimiters[0]` → ','

Reference:
C++23 §23.3.6 — vector element type requirements
C++23 §7.1.5 — List initialization rules
*/

#include <vector>
#include <iostream>

int main() {
    // std::vector<char> delimiters = { ",", ";" }; // ❌ Compilation error
    std::vector<char> delimiters = { ',', ';' };    // ✅ Correct
    std::cout << delimiters[0];                     // prints ','
}
