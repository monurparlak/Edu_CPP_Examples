/*
Question #33
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Print an Inverted Pyramid Star Pattern.

My Answer:
✅ Output:
*********
 *******
  *****
   ***
    *

Reason:
- Dış döngü `rows`’tan 1’e kadar gidiyor, satırları kontrol ediyor.
- İlk iç döngü boşlukları yazdırıyor, piramitin ortalanmasını sağlıyor.
- İkinci iç döngü `*` yazdırıyor, formül `(2*i - 1)` yıldız sayısını veriyor.
- Satır sonunda `endl` ile alt satıra geçiyoruz.

If Wrong:
Kontrol et: Döngü limitleri ve boşluk/yıldız formülü doğru mu.
*/

#include <iostream>
using namespace std;

int main()
{
    int rows = 5;

    for (int i = rows; i >= 1; i--) {
        for (int j = rows; j > i; j--) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
