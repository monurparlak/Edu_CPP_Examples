/*
Question #2
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 12

Reason:
- "foo" is a string literal of type const char[4].
- It can convert to std::string (implicit constructor) or to const void*.
- Overload resolution prefers std::string match over const void*.
- So f(const std::string&) is chosen → prints 1.
- bar is of type const char*.
- It can match const void* directly, or std::string via constructor.
- Pointer conversion to const void* is ranked higher than to class type here.
- So f(const void*) is chosen → prints 2.
- Combined output: 12.

If Wrong:
To force both calls to f(const std::string&):
    f(std::string("foo"));
    f(std::string(bar));

Reference:
C++23 §12.2.4.2 — Overload resolution and standard conversions
*/

#include <iostream>
#include <string>

void f(const std::string &) { std::cout << 1; }
void f(const void *)        { std::cout << 2; }

int main() {
    f("foo"); // calls f(const std::string&) → prints 1
    const char *bar = "bar";
    f(bar);   // calls f(const void*) → prints 2
}
