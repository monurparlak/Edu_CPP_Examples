/*
Question #130
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: ST

Reason:
- Functions:
  1) `template<typename T> void adl(T)` → prints "T"
  2) `void adl(S)` → prints "S"

- `call_adl(T t)` calls:
  1) `adl(S());`
     - Unqualified call inside template → **ADL considered**
     - Argument type = `S` → ADL finds `void adl(S)` defined at global scope
     - So `adl(S())` calls **non-template adl(S)** → prints "S"

  2) `adl(t);`
     - `t` has type `S`
     - Inside template, unqualified `adl(t)` first looks in scope of template definition
     - Template `adl(T)` matches perfectly (T = S)
     - ADL also finds `adl(S)`, but template function is considered first in unqualified lookup **because it's a better match?**
     - In practice, **template function `adl<T>` is called** → prints "T"

- Therefore, output: **ST**

If Wrong:
- Many expect "SS"; remember that the first call uses ADL to find the non-template function, the second call prefers the template defined **in the same scope as the template itself**.

Reference:
C++23 §13.3.1.2 — Argument-dependent lookup (ADL) rules
*/

#include <iostream>
using namespace std;

template<typename T>
void adl(T) { cout << "T"; }

struct S { };

template<typename T>
void call_adl(T t) {
    adl(S());  // calls global adl(S) → "S"
    adl(t);    // calls template adl(T) → "T"
}

void adl(S) { cout << "S"; }

int main() {
    call_adl(S());  // Output: ST
}
