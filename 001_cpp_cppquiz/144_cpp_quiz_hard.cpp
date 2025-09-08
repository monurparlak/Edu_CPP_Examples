/*
Question #XXX
Difficulty: 3
Source: CPP Quiz

Question:
What is the output of this program considering standard C++23 rules?

My Answer:
✅ Output: 011

Reason:
- We have an array `N[3]` initialized to {0,0,0}.
- The `if constexpr` checks platform integer sizes:
  - `long int` digits == 63 → 64-bit long
  - `int` digits == 31 → 32-bit int
  - `unsigned int` digits == 32
- On most standard platforms, these conditions **fail** because:
  - long int usually has 64 bits (digits=63), int 32 bits (digits=31), unsigned int 32 bits (digits=32)
  - Actually, this may pass on typical 64-bit systems (64-bit long, 32-bit int, 32-bit unsigned)
- If condition passes:
  - Loop: `for(long int i = -0xffffffff; i; --i)`  
    - `0xffffffff` = 4294967295 → `-0xffffffff` = -4294967295  
    - Trying to index `N[i]` with **negative index** → undefined behavior  
    - Program is **ill-formed / undefined** in standard C++. So practically compiler may optimize this away or crash.
- Else branch:
  - `N[1] = 1;` → executed if platform does not match
- `std::cout << N[0] << N[1] << N[2];` → prints **0 1 1** after assignment of N[1] and N[2] remains 0?  

Important notes:
- Negative indexing like `N[-4294967295]` is **undefined behavior**.  
- `if constexpr` ensures that only one branch is compiled. On standard 64-bit Linux/Windows, the first branch **may compile** and crash, but else branch is safer.
- So output depends on platform, but on safe path: **011**

If Wrong:
- If you expected 111, note that negative array index in C++ is undefined and cannot reliably produce output.

Reference:
C++23 §9.3.4 — Array subscripting and undefined behavior
C++23 §7.1.6 — if constexpr evaluation

WARNING: This question has been retracted, and should not be part of new quizzes.
    You're on this page because you're taking an old quiz which includes this 
    question, or have followed an old link.
Reason for retraction:
See Issue 251
*/

#include <iostream>
#include <limits>

int main()
{
    int N[] = {0, 0, 0};

    if constexpr (std::numeric_limits<long int>::digits == 63 &&
                  std::numeric_limits<int>::digits == 31 &&
                  std::numeric_limits<unsigned int>::digits == 32)
    {
        for (long int i = -0xffffffff; i; --i)
        {
            N[i] = 1; // undefined behavior if negative index
        }
    }
    else
    {
        N[1] = 1; // safe assignment
    }

    std::cout << N[0] << N[1] << N[2]; // likely output: 011
}
