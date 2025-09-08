/*
Question #54
Source: CPP GeeksforGeeks

Question:
Write a C++ program to convert an octal number to its binary equivalent.

✅ Output:

Equivalent Binary Value = 011100101

Reason:
- Each octal digit corresponds to 3 binary bits.
- Traverse each digit of the octal number and append its 3-bit binary equivalent.
- This approach avoids converting to decimal first and directly builds the binary string.
*/

#include <iostream>
using namespace std;

// Function to convert Octal to Binary
string OctToBin(string octnum)
{
    long int i = 0;
    string binary = "";

    while (octnum[i]) {
        switch (octnum[i]) {
        case '0': binary += "000"; break;
        case '1': binary += "001"; break;
        case '2': binary += "010"; break;
        case '3': binary += "011"; break;
        case '4': binary += "100"; break;
        case '5': binary += "101"; break;
        case '6': binary += "110"; break;
        case '7': binary += "111"; break;
        default:
            cout << "\nInvalid Octal Digit " << octnum[i];
            break;
        }
        i++;
    }

    return binary;
}

int main()
{
    string octnum = "345";

    cout << "Equivalent Binary Value = " << OctToBin(octnum);

    return 0;
}