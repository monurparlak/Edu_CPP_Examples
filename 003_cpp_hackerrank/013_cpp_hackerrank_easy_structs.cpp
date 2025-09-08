/*
================================================================================
HackerRank C++ Challenge: Structs - Student Details
================================================================================

Objective:
----------
- Learn to define and use structs in C++.
- Store multiple fields of related data in a single composite type.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Struct Declaration:
   struct Student {
       int age;
       string first_name;
       string last_name;
       int standard;
   };

2. Accessing Struct Members:
   Student s;
   s.age = 15;
   s.first_name = "john";

3. Input / Output:
   cin >> s.age;
   cin >> s.first_name;
   cout << s.age << " " << s.first_name << endl;

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- Four lines:
  1. Integer: age
  2. String: first_name
  3. String: last_name
  4. Integer: standard

Example Input:
15
john
carmack
10

Expected Output:
15 john carmack 10
*/

#include <iostream>
#include <string>
using namespace std;

// Define struct Student with required fields
struct Student {
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main() {
    Student s;

    // Read student details
    cin >> s.age;
    cin >> s.first_name;
    cin >> s.last_name;
    cin >> s.standard;

    // Print student details in one line separated by spaces
    cout << s.age << " " << s.first_name << " " << s.last_name << " " << s.standard << endl;

    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Use struct to group related data into a single type.
2. Members of a struct are accessed using the dot operator (.).
3. Structs provide a foundation for more advanced object-oriented programming.
4. Strings in C++ can be directly stored as struct members.
================================================================================
*/
