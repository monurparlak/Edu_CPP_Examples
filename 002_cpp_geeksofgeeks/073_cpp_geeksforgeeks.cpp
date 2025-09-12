/*
Question #73
Source: CPP GeeksforGeeks

Question:
Write a C++ program to calculate the frequency
of each word in a given string.

My Answer:
✅ Output:
Geeks - 3
For - 1
is - 1
for - 1

Reason:
- Approach:
  1. Use a `map<string, int>` to store word frequencies.
  2. Iterate through the string:
     - Build a word character by character.
     - On encountering a space, check if the word exists in the map:
       - If not, insert with frequency 1.
       - If yes, increment its frequency.
     - Reset word after processing.
  3. After the loop, update frequency of the last word.
  4. Traverse the map and print each word with its count.
- The program counts words exactly as they appear (case-sensitive).

If Wrong:
- Watch for the last word in the string — must be processed after loop.
- Consider case-sensitivity if required (e.g., "Geeks" vs "geeks").
*/

#include <bits/stdc++.h>
using namespace std;

void printFrequency(string str)
{
    map<string, int> M;
    string word = "";

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            if (!word.empty()) {
                M[word]++;
                word = "";
            }
        }
        else
            word += str[i];
    }

    if (!word.empty())
        M[word]++;

    for (auto& it : M) {
        cout << it.first << " - " << it.second << endl;
    }
}

int main()
{
    string str = "Geeks For Geeks is for Geeks";
    printFrequency(str);
    return 0;
}
