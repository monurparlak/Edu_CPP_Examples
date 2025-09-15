/* ================================================================================
HackerRank C++ Challenge: Virtual Functions with Professor and Student Classes
================================================================================

Objective:
----------
- Practice using virtual functions, inheritance, and static class members in C++.
- Implement two derived classes (Professor and Student) from a base class (Person).
- Assign sequential IDs to each Professor and Student starting from 1.
- Gather input for each object and print the required output.

Concepts Covered:
-----------------
- Class inheritance
- Virtual functions (pure virtual functions)
- Static members for unique IDs
- Dynamic memory allocation and polymorphism
- Data types:
  * string: for name
  * int: for age, marks, publications, IDs

--------------------------------------------------------------------------------
Problem Description:
--------------------------------------------------------------------------------
- Base class Person has name and age.
- Derived class Professor has additional data members: publications and cur_id.
- Derived class Student has additional data members: marks[6] and cur_id.
- Each derived class must implement getdata() and putdata() as virtual functions.
- Sequential IDs are assigned using static members.

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- First line: integer n, number of objects to create.
- Next n blocks:
  * First integer val: 1 for Professor, 2 for Student
  * Followed by input for name, age, and other relevant fields (publications or marks[6]).

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- For each Professor: name age publications cur_id
- For each Student: name age sum_of_marks cur_id

--------------------------------------------------------------------------------
Sample Input:
4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87

Sample Output:
Walter 56 99 1
Jesse 18 403 1
Pinkman 22 135 2
White 58 87 2

================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

// --------------------------
// Base class Person
// --------------------------
class Person {
protected:
    string name; // Name of the person
    int age;     // Age of the person
public:
    // Pure virtual functions to enforce overriding in derived classes
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

// --------------------------
// Derived class Professor
// --------------------------
class Professor : public Person {
private:
    int publications;       // Number of publications
    int cur_id;             // Unique ID for each Professor
    static int id_counter;  // Static counter for generating IDs
public:
    Professor() {
        cur_id = ++id_counter;  // Increment static counter and assign
    }

    // Read input data for Professor
    void getdata() override {
        cin >> name >> age >> publications;
    }

    // Print Professor data
    void putdata() override {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

// Initialize static member for Professor IDs
int Professor::id_counter = 0;

// --------------------------
// Derived class Student
// --------------------------
class Student : public Person {
private:
    int marks[6];           // Array to store 6 marks
    int cur_id;             // Unique ID for each Student
    static int id_counter;  // Static counter for generating IDs
public:
    Student() {
        cur_id = ++id_counter;  // Increment static counter and assign
    }

    // Read input data for Student
    void getdata() override {
        cin >> name >> age;
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }

    // Print Student data with sum of marks
    void putdata() override {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += marks[i];
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
};

// Initialize static member for Student IDs
int Student::id_counter = 0;

// --------------------------
// Main function
// --------------------------
int main(){
    int n, val;
    cin >> n; // Number of objects
    Person *per[n]; // Array of base class pointers to handle polymorphism

    for(int i = 0; i < n; i++){
        cin >> val; // Determine object type: 1=Professor, 2=Student
        if(val == 1){
            per[i] = new Professor;
        } else {
            per[i] = new Student;
        }
        per[i]->getdata(); // Polymorphic call to read object data
    }

    // Print data for all objects
    for(int i = 0; i < n; i++)
        per[i]->putdata(); // Polymorphic call to print object data

    // Free dynamically allocated memory
    for(int i = 0; i < n; i++)
        delete per[i];

    return 0;
}

