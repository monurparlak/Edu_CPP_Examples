/*
Question #147
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 1

Reason:
- `int x = 0;` → declares an integer x and initializes it to 0. Nothing wrong.
- `x = 1;` → assigns 1 to x.
- `std::cout << x;` → prints current value of x, which is 1.
- The comment `//What is wrong here??` is misleading; code is perfectly valid.

If Wrong:
- Some might think the comment indicates an error, but the program is standard C++23 compliant.
- No compilation errors occur; output is deterministic.

Reference:
C++23 §6.7.1 — Simple variable declarations and initialization

WARNING: This question has been retracted, and should not be part of new quizzes.
    You're on this page because you're taking an old quiz which includes this question,
    or have followed an old link.
Reason for retraction:
This question no longer makes sense after trigraphs were removed.
*/

#include <iostream>
using namespace std;

int main() {
    int x = 0; // declaration & initialization
    x = 1;     // assignment
    cout << x; // prints 1
    return 0;  // Output: 1
}
