/*
Question #60
Source: CPP GeeksforGeeks

Question: Demonstrate single-level inheritance where Student inherits from Person.

My Answer:
✅ Output:
132451    XYZ    ABC    100000

Reason:
- `Person` class has `id` and `name` with setters and display function.
- `Student` privately inherits from `Person`, so `Person`'s public members become private in `Student`.
- `set_s()` in `Student` calls `set_p()` of `Person` to initialize `id` and `name`.
- `display_s()` calls `display_p()` and then prints `course` and `fee`.
- In main(), `s.set_s()` and `s.display_s()` correctly initialize and display all fields.
- Private inheritance prevents `Person`'s methods from being directly accessed via `Student` objects.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Person {
    int id;
    char name[100];

public:
    void set_p(int id, char* name)
    {
        strcpy(this->name, name);
        this->id = id;
    }

    void display_p()
    {
        cout << id << "\t" << name << "\t";
    }
};

class Student : private Person {
    char course[50];
    int fee;

public:
    void set_s(int id, char* name, char* course, int fee)
    {
        set_p(id, name);
        strcpy(this->course, course);
        this->fee = fee;
    }

    void display_s()
    {
        display_p();
        cout << course << "\t" << fee << endl;
    }
};

int main()
{
    Student s;
    char name[] = "XYZ";
    char course[] = "ABC";
    s.set_s(132451, name, course, 100000);
    s.display_s();
    return 0;
}
