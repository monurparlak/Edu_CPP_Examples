/*
Question #34
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Print a Triangle Star Pattern.

My Answer:
✅ Output:
*
**
***
****
*****

Reason:
- `rows` kadar dış döngü ile satır sayısını kontrol ediyoruz.
- İç döngü satır numarasına kadar yıldız (`*`) yazdırıyor.
- Satır sonunda `endl` ile alt satıra geçiyoruz.

If Wrong:
Kontrol et: Döngü limitleri ve cout kullanımı doğru mu.
*/

#include <iostream>
using namespace std;

int main()
{
    int rows = 5;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
