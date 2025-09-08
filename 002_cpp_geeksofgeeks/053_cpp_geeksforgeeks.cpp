/*
Question #53
Source: CPP GeeksforGeeks

Question:
Write a C++ program to convert a binary number to its octal equivalent.

✅ Output:
Octal number = 3645241.26666

Reason:
- Binary numbers can be grouped 3 bits at a time to get the octal digit.
- Add leading or trailing zeros so the number of bits is divisible by 3.
- Map each 3-bit group to its octal equivalent using a hash map for efficiency.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to create map between binary and octal
void createMap(unordered_map<string, char>* um)
{
    (*um)["000"] = '0';
    (*um)["001"] = '1';
    (*um)["010"] = '2';
    (*um)["011"] = '3';
    (*um)["100"] = '4';
    (*um)["101"] = '5';
    (*um)["110"] = '6';
    (*um)["111"] = '7';
}

// Function to convert binary to octal
string convertBinToOct(string bin)
{
    int l = bin.size();
    int t = bin.find_first_of('.');

    // length of string before '.'
    int len_left = t != -1 ? t : l;

    // add leading zeros to make length divisible by 3
    for (int i = 1; i <= (3 - len_left % 3) % 3; i++)
        bin = '0' + bin;

    // if decimal point exists, add trailing zeros
    if (t != -1) {
        int len_right = l - len_left - 1;
        for (int i = 1; i <= (3 - len_right % 3) % 3; i++)
            bin = bin + '0';
    }

    unordered_map<string, char> bin_oct_map;
    createMap(&bin_oct_map);

    int i = 0;
    string octal = "";

    while (i < bin.size()) {
        if (bin[i] == '.') {
            octal += '.';
            i++;
            continue;
        }
        octal += bin_oct_map[bin.substr(i, 3)];
        i += 3;
    }

    return octal;
}

int main()
{
    string bin = "1111001010010100001.010110110011011";
    cout << "Octal number = " << convertBinToOct(bin);
    return 0;
}