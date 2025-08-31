/*
Question #116
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 112212

Reason:
We have two overloads of y():
- y(int&)  → prints 1
- y(int&&) → prints 2

Templates:
- f(T&& x): calls y(x)
- g(T&& x): calls y(std::move(x))
- h(T&& x): calls y(std::forward<T>(x))

Step by step:

1) f(i)
- i is lvalue int.
- T deduces to int& (reference collapsing: T&& → int&).
- So parameter type is int&.
- Inside y(x): x is an lvalue (named variable).
- So overload resolution → y(int&) → prints 1.

2) f(20)
- 20 is rvalue int.
- T deduces to int.
- Parameter type: int&&.
- Inside y(x): x is a named variable → always lvalue.
- So overload resolution → y(int&) → prints 1.

→ f(i), f(20) → "11"

3) g(i)
- i is lvalue int.
- T deduces to int&.
- Parameter type: int&.
- Inside call: y(std::move(x)) → rvalue.
- So overload resolution → y(int&&) → prints 2.

4) g(20)
- 20 is rvalue int.
- T deduces to int.
- Parameter type: int&&.
- Inside call: y(std::move(x)) → rvalue.
- So overload resolution → y(int&&) → prints 2.

→ g(i), g(20) → "22"

5) h(i)
- i is lvalue int.
- T deduces to int&.
- Parameter type: int&.
- Inside call: y(std::forward<int&>(x)).
- std::forward<int&>(x) returns int& (lvalue).
- So overload resolution → y(int&) → prints 1.

6) h(20)
- 20 is rvalue int.
- T deduces to int.
- Parameter type: int&&.
- Inside call: y(std::forward<int>(x)).
- std::forward<int>(x) returns int&& (rvalue).
- So overload resolution → y(int&&) → prints 2.

→ h(i), h(20) → "12"

Final output: "11 22 12" → concatenated as **112212**

If Wrong:
If you expected "121212", you forgot that in f(), 'x' is always an lvalue
because it is a named variable inside the function.

Reference:
C++23 §13.10.3.2 — Forwarding references and std::forward
*/

#include <iostream>
#include <utility>
using namespace std;

int y(int &) { return 1; }
int y(int &&) { return 2; }

template <class T> int f(T &&x) { return y(x); }
template <class T> int g(T &&x) { return y(move(x)); }
template <class T> int h(T &&x) { return y(forward<T>(x)); }

int main() {
    int i = 10;
    cout << f(i) << f(20); // 11
    cout << g(i) << g(20); // 22
    cout << h(i) << h(20); // 12
    return 0;              // Output: 112212
}
