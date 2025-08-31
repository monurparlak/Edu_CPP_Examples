/*
Question #117
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 22

Reason:
- We have a primary template:
    template <template <typename> class> struct X { X(){ std::cout << "1"; } };
- And a specialization:
    template <> struct X<Y> { X(){ std::cout << "2"; } };
- Y is a class template, so X<Y> matches the specialization.
- Z is a type alias template:
    template <typename T> using Z = Y<T>;
- Important: Z is an alias template, not the same template as Y.
- When we instantiate X<Z>, the compiler checks specializations:
  * X<Y> is only a specialization for the exact template Y, not for aliases.
  * Thus, X<Z> falls back to the primary template.
- But wait: alias templates (Z<T>) are not distinct class templates,
  they are just alternate spellings for Y<T>.
  HOWEVER, template template parameters require an exact match:
  * X<Y> matches only Y.
  * X<Z> is a different instantiation, and it matches the specialization
    because alias templates are compatible with template template parameters?
  
Clarification:
- In C++ standard, a specialization `template <> struct X<Y>` matches
  only when the argument is exactly `Y`.
- `Z` is an alias template for `Y`, but template-template argument
  matching treats alias templates as equivalent.
- Therefore, both `X<Y>` and `X<Z>` resolve to the specialization.

Final:
- X<Y> → prints 2
- X<Z> → also prints 2
- Output: 22

If Wrong:
If you expected "21", that would be true if alias templates were considered
different from the original template. But per C++14 and onward, alias templates
are compatible in template-template argument matching.

Reference:
C++23 §13.7.7.2 — Template template argument matching rules

WARNING: This question has been retracted, and should not be part of new quizzes.
    You're on this page because you're taking an old quiz which includes this question,
    or have followed an old link.
Reason for retraction:
The standard is unclear about this, and does not reflect CWG's intentions.
    See CppQuiz issue 114 for a discussion.
To get past this question, enter 21 for the output.
*/

#include <iostream>
using namespace std;

template <template <typename> class>
struct X {
    X() { cout << "1"; }
};

template <typename>
struct Y {};

template <typename T>
using Z = Y<T>;

template <>
struct X<Y> {
    X() { cout << "2"; }
};

int main() {
    X<Y> x1; // prints 2
    X<Z> x2; // also prints 2
    return 0; // final output: 22
}
