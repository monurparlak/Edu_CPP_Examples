/*
Question #35
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 22

Reason:
Step-by-step:

1. `std::vector<int> v1(1, 2);`
   - Parentheses constructor with two arguments: `(size_type count, const T& value)`.
   - Creates a vector with 1 element, value `2`.
   - `v1.size() = 1`.

2. `std::vector<int> v2{ 1, 2 };`
   - Brace initialization invokes **initializer_list constructor** if available.
   - Creates a vector with elements `1` and `2`.
   - `v2.size() = 2`.

⚠ Wait — double check!  
- `v1.size()` = 1 → prints `1`  
- `v2.size()` = 2 → prints `2`  

So final output: `"12"` ✅

If Wrong:
A common mistake is to assume `v1` also gets 2 elements, confusing `(1, 2)` with `{1, 2}` initializer list syntax. Parentheses constructor `(1,2)` creates 1 element of value 2. Brace `{1,2}` creates 2 elements from the initializer list.

Reference:
C++23 §23.3.6.2 — `vector` constructors
C++23 §12.6.2 — List-initialization rules
*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1(1, 2);
  std::vector<int> v2{ 1, 2 };
  std::cout << v1.size() << v2.size();
}
