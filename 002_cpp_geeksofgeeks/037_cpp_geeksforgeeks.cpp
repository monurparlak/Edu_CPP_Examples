/*
Question #37
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Reverse a String using Iteration.

My Answer:
✅ Output: skeeGrofskeeG

Reason:
- Get the string length.
- Use a for döngüsü: sondan başa doğru karakterleri yazdır.
- Çıktı ters sıradaki string olacak.

If Wrong:
Check that loop başlama ve bitiş koşulları doğru: i = len-1; i >= 0; i--
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "GeeksforGeeks";
    int len = str.size();

    cout << "Reverse of the string: ";
    for (int i = len - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;

    return 0;
}

