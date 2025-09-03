/*
Question #36
Source: CPP GeeksforGeeks

Question:
Write a C++ Program to Print Pascal’s Triangle.

My Answer:
✅ Output: 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 


Reason:
- 2 boyutlu bir dizi tanımlandı: arr[n][n]
- Her satırın baş ve son elemanı 1 olarak atanır.
- Orta elemanlar üst satırdaki iki elemanın toplamı olarak bulunur.
- Her satır yazdırılır.

If Wrong:
Kontrol et: arr boyutu n x n ve indexler doğru mu.
*/

#include <iostream>
using namespace std;

void printPascal(int n)
{
    int arr[n][n];

    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++) {
            if (line == i || i == 0)
                arr[line][i] = 1;
            else
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];

            cout << arr[line][i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n = 6;
    printPascal(n);
    return 0;
}
