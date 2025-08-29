/*
Question #109
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 42

Reason:
- The template function call_with takes a std::function<void(T)> and a T.
- In main(), print is a lambda equivalent to void(int).
- When passing 'print' to call_with, the lambda can be converted to
  std::function<void(int)> because it is copyable and matches the signature.
- T is deduced as int from the argument '42'.
- Therefore, call_with invokes f(42), which calls the lambda and prints 42.

If Wrong:
If you expected a compile error, note that std::function has a constructor
that accepts compatible callables such as lambdas.
If you wanted perfect forwarding, the template should be written differently:
    template <typename F, typename T>
    void call_with(F&& f, T&& val) { std::forward<F>(f)(std::forward<T>(val)); }

Reference:
C++23 §20.14.11 — std::function constructor and callable compatibility
*/

#include <functional>
#include <iostream>
using namespace std;

template <typename T>
void call_with(function<void(T)> f, T val) {
    f(val);
}

int main() {
    auto print = [] (int x) { cout << x; };
    call_with(print, 42); // prints 42
    return 0;
}
