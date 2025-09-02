/*
Question #35
Source: CPP GeeksforGeeks

Question:
Write a C++/C Program to Print Floyd's Triangle.

My Answer:
✅ Output:
1 
2 3 
4 5 6 
7 8 9 10 


Reason:
- Bir `n` sayacı başlatıldı (1’den başlayarak)
- Dış döngü satırları, iç döngü satırdaki eleman sayısını kontrol eder.
- Her satırda sayıları yazdır ve n’i artır.
- Satır sonunda yeni satıra geç.

If Wrong:
Kontrol et: Döngü limitleri ve n sayacı doğru mu.
*/

#include <iostream>
using namespace std;

int main()
{
    int rows = 4;
    int n = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << n++ << " ";
        }
        cout << "\n";
    }
    return 0;
}
