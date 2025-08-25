/*
Question #2
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 12

Reason:
Step-by-step:

1. `f("foo");`
   - "foo" is a string literal of type const char[4].
   - It can convert to std::string (via constructor) or const void*.
   - f(const std::string&) is preferred because converting to string
     is better than converting to const void*.
   - Prints "1".

2. `const char *bar = "bar"; f(bar);`
   - bar is const char*.
   - Can convert to std::string or const void*.
   - No user-defined conversion is better than exact pointer match.
   - f(const void*) is chosen → prints "2".

Concatenate (Final Result): "12"

If Wrong:
- If you answered "11": you assumed both calls convert to std::string.
  The second call prefers exact pointer match.
- If you answered "22": wrong, first call prefers std::string.
- If you answered "compile error": all overloads are valid.

Reference:
- C++23 §13.3.3 — Overload resolution and ranking of conversions
- C++23 §12.2.2 — Standard conversions and user-defined conversions
*/

/* Actual Program Code: */

#include <iostream>
#include <string>

void f(const std::string &) { std::cout << 1; }
void f(const void *)        { std::cout << 2; }

int main() {
  f("foo");
  const char *bar = "bar";
  f(bar);
}
