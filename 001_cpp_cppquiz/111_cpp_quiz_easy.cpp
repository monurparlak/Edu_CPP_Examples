/*
Question #111
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 1

Reason:
- The loop is `do { ... } while(false);` → executes the body **exactly once**.
- Inside the body:
    - i = 1 → prints 1
    - i incremented → i = 2
    - `if(i < 3) continue;` → condition true → continue executed
- **Important:** `continue` in a do-while loop jumps to the condition check at the end.
- Condition is `false` → loop exits immediately.
- No further iterations occur.
- Therefore, only "1" is printed.

If Wrong:
- If you expected "12", note that continue does **not restart the loop body** again; it jumps to the condition check.

Reference:
C++23 §8.5.5 — continue statement in do-while loops
*/

#include <iostream>
using namespace std;

int main() {
    int i = 1;
    do {
        cout << i; // prints 1
        i++;
        if (i < 3) continue; // jumps to while(false) → exits
    } while(false);
    return 0; // Output: 1
}
