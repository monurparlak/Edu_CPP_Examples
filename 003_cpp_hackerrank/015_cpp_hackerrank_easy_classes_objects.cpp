/*
================================================================================
HackerRank C++ Challenge: Classes - Student Scores
================================================================================

Objective:
----------
- Learn to define and use classes in C++.
- Store and process student exam scores.

--------------------------------------------------------------------------------
Concepts Covered:
--------------------------------------------------------------------------------
1. Class Declaration:
   class Student {
       private:
           vector<int> scores;
       public:
           void input();
           int calculateTotalScore();
   };

2. Member Functions:
   - input(): Reads 5 integers (exam scores) from stdin and stores them in the vector.
   - calculateTotalScore(): Returns the sum of the scores.

3. Object Arrays:
   - An array of Student objects is created dynamically: Student *s = new Student[n];
   - Each student's scores are read using a loop.

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- The first line contains an integer n: number of students.
- The next n lines contain 5 integers each: the exam scores for each student.

Example Input:
3
30 40 45 10 10
40 40 40 10 10
50 20 30 10 10

Expected Output:
1
Explanation:
Kristen is the first student (line 1). Only 1 student scored higher than her.
*/

#include <iostream>
#include <vector>
using namespace std;

// ==============================
// Student Class Definition
// ==============================
class Student {
private:
    vector<int> scores; // Stores 5 exam scores

public:
    // ------------------------------
    // Read 5 scores from stdin
    // ------------------------------
    void input() {
        int score;
        for (int i = 0; i < 5; i++) {
            cin >> score;
            scores.push_back(score);
        }
    }

    // ------------------------------
    // Calculate total score of the student
    // ------------------------------
    int calculateTotalScore() {
        int total = 0;
        for (int s : scores) {
            total += s;
        }
        return total;
    }
};

// ==============================
// Main Function
// ==============================
int main() {
    int n; // number of students
    cin >> n;

    // dynamically create an array of Student objects
    Student *s = new Student[n];

    // read input for each student
    for (int i = 0; i < n; i++) {
        s[i].input();
    }

    // calculate Kristen's total score (first student)
    int kristen_score = s[0].calculateTotalScore();

    // count how many students scored higher than Kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].calculateTotalScore() > kristen_score) {
            count++;
        }
    }

    // print result
    cout << count << endl;

    delete[] s; // free allocated memory
    return 0;
}

/*
================================================================================
Notes and Tips:
--------------------------------------------------------------------------------
1. Classes allow grouping data (scores) and related operations (input, total) together.
2. Vector is a dynamic array that can store the exam scores easily.
3. Loops are used for input and summation.
4. Dynamic allocation with new[] allows creating arrays of objects at runtime.
5. Always free memory allocated with new[] using delete[].
================================================================================
*/

