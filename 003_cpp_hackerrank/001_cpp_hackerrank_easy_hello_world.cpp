/*
================================================================================
HackerRank C++ Challenge: Say "Hello, World!" With C++
================================================================================

Objective:
----------
This is one of the most fundamental challenges for beginners in C++.
The goal is to help you practice **printing output to the standard output (stdout)**.
You can use either:
  1. cout (from C++ standard library)
  2. printf (from C standard library)

Before attempting this challenge, you may want to complete "Solve Me First" in C++.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Standard Output (stdout):
   - stdout is the standard output stream where text or data is printed.
   - In C++, this is typically done using 'cout' from the iostream library.
   - In C, 'printf' is used, which allows formatted output.

2. C++ cout:
   - Syntax: cout << value1 << value2 << ... << valueN;
   - Can print strings, numbers, variables, or expressions.
   - Does not automatically append a newline unless you add 'endl' or "\n".
   - Example:
       cout << "Hello" << " World!" << endl; // Outputs: Hello World!

3. C printf:
   - Syntax: printf(format_string, variables...);
   - Format specifiers define the type of variable being printed:
       - %s -> string
       - %d -> integer
       - %f -> float/double
   - printf does not automatically append a newline; use "\n" at the end.
   - Example:
       printf("Hello, World!\n");

--------------------------------------------------------------------------------
Expected Output:
--------------------------------------------------------------------------------
Print exactly the following to stdout:

Hello, World!

Notes:
------
- Extra spaces or missing characters will result in a wrong answer.
- The output must match **exactly**.
- No input is required for this challenge.
- You may use either 'cout' or 'printf', but 'cout' is the more idiomatic C++ approach.

--------------------------------------------------------------------------------
Step-by-Step Solution:
--------------------------------------------------------------------------------
1. Include the necessary library for C++ input/output:
       #include <iostream>

2. Use the standard namespace to avoid typing 'std::' repeatedly:
       using namespace std;

3. Define the main function which is the entry point of a C++ program:
       int main() { ... }

4. Use cout to print the required string:
       cout << "Hello, World!" << endl;

5. Alternatively, use printf (C-style):
       printf("Hello, World!\n");

6. Return 0 from main to indicate successful execution:
       return 0;

--------------------------------------------------------------------------------
Common Mistakes:
--------------------------------------------------------------------------------
1. Forgetting #include <iostream>:
   - Causes compilation error: 'cout' was not declared in this scope.
2. Omitting 'endl' or '\n':
   - Output will not end with a newline; may fail HackerRank test cases.
3. Typo in "Hello, World!":
   - Output must be exact, including comma and exclamation mark.

--------------------------------------------------------------------------------
Advanced Notes:
--------------------------------------------------------------------------------
- cout is part of the C++ Standard Library (namespace std).
- endl flushes the output buffer in addition to adding a newline.
- For large output, using "\n" may be faster than endl, but for small beginner examples, it does not matter.
- printf allows formatted output which is essential for more advanced challenges.

--------------------------------------------------------------------------------
Sample Code:
--------------------------------------------------------------------------------
*/

#include <iostream> // Standard library for input/output operations
using namespace std; // Use standard namespace to avoid std:: prefix

int main() {
    // ------------------------------
    // Using C++ style output (recommended)
    // ------------------------------
    cout << "Hello, World!" << endl; // Print string with newline

    // ------------------------------
    // Using C style output (optional)
    // ------------------------------
    // printf("Hello, World!\n"); // Uncomment to use printf instead

    return 0; // Indicate successful execution
}

/*
================================================================================
End of Detailed Template
================================================================================
This template covers:
- Basic I/O in C++ (cout)
- C-style printing (printf)
- Step-by-step solution
- Common pitfalls and mistakes
- Advanced tips for newline and output flushing

You can reuse this template for all beginner-level HackerRank printing challenges.
================================================================================
*/
