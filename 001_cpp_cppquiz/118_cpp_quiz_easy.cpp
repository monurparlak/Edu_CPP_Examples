/*
Question #118
Difficulty: 1
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: abc0A

Reason:
- First call: print("abc");
  - String literal "abc" is of type const char[4], which decays to const char*.
  - Matches print(const char*). → prints "abc".
- Second call: print(0);
  - 0 is an int. Overload candidates are print(const char*) and print(short).
  - Converting 0 to const char* is allowed (null pointer constant), but
    converting int → short is a standard conversion.
  - Standard conversion is preferred over a pointer conversion in overload
    resolution. → print(short) is chosen. Prints 0.
- Third call: print('A');
  - 'A' is a character literal of type int in C++ (not char).
  - Overload candidates: const char* vs short.
  - int → short is a standard conversion; int → const char* is not viable.
  - So print(short) is chosen. 'A' has ASCII value 65. But since it's narrowed
    to short, the printed result is 65. BUT careful: with std::cout << num,
    printing short promotes to int, so prints "65".
  - So actual printed sequence is: abc065

If Wrong:
If you expected "abc0A", that's incorrect because there is no overload of
print(char). 'A' is treated as int (value 65), not char.

Reference:
C++23 §12.4.2 — Overload resolution rules and standard conversions
*/

#include <iostream>
using namespace std;

void print(const char *str) { cout << str; }
void print(short num) { cout << num; }

int main() {
    print("abc"); // prints "abc"
    print(0);     // prints 0
    print('A');   // prints 65
    return 0;     // final output: abc065
}
