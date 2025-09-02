/*
Question #34
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Print a Simple Pyramid Star Pattern.

My Answer:
✅ Output:
     *
    ***
   *****
  *******
 *********

Reason:
- Dış döngü `i` 1’den `rows`’a kadar gidiyor, her satırı temsil ediyor.
- İlk iç döngü satır başındaki boşlukları yazdırıyor, piramidin ortalanması için.
- İkinci iç döngü `(2*i - 1)` yıldız yazıyor.
- `endl` ile satır bitince alt satıra geçiliyor.

If Wrong:
- Boşluk ve yıldız sayısını kontrol et. Döngü limitleri doğru mu?
*/

#include <iostream>
using namespace std;

int main()
{
    int rows = 5;

    for (int i = 1; i <= rows; i++) {
        for (int j = rows; j >= i; j--) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
