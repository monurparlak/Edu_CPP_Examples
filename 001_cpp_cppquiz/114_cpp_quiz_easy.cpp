/*
Question #114
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: AAA BBB

Reason:
- Class C has two overloads of foo():
    void foo()       → prints "A"
    void foo() const → prints "B"
- s is non-const:
    - s.v[0].foo()   → non-const object → calls foo() → "A"
    - s.u->foo()     → non-const object → calls foo() → "A"
    - s.p->foo()     → non-const pointer → calls foo() → "A"
- r is a const reference to s:
    - r.v[0].foo()   → const object via reference → calls foo() const → "B"
    - r.u->foo()     → unique_ptr points to non-const object, but u itself
      is accessed through const reference. Dereferencing gives const C& → calls foo() const → "B"
    - r.p->foo()     → pointer is const-qualified through reference → C* const → foo() const → "B"
- Therefore, first three calls print "AAA", next three print "BBB".

If Wrong:
If you expected "AAAAAA", remember that const references trigger
the const-qualified member function overloads.

Reference:
C++23 §11.3.1 — cv-qualified member functions and overload resolution
*/

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class C {
public:
    void foo()       { cout << "A"; }
    void foo() const { cout << "B"; }
};

struct S {
    vector<C> v;
    unique_ptr<C> u;
    C* const p;

    S()
        : v(1)
        , u(new C())
        , p(u.get())
    {}
};

int main() {
    S s;
    const S& r = s;

    s.v[0].foo(); // A
    s.u->foo();   // A
    s.p->foo();   // A

    r.v[0].foo(); // B
    r.u->foo();   // B
    r.p->foo();   // B
    // Output: AAA BBB

    return 0;
}
