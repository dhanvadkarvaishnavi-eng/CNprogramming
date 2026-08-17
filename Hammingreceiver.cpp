#include <iostream>
#include <string>
using namespace std;

int main()
{
    string code;

    cout << "Enter received Hamming codeword: ";
    cin >> code;

    int n = code.length();

    if (n != 7)
    {
        cout << "\nPlease enter a 7-bit Hamming codeword.";
        return 0;
    }

    int bit[8];

    for (int pos = 1; pos <= 7; pos++)
    {
        bit[pos] = code[7 - pos] - '0';
    }

    int r1 = bit[1] ^ bit[3] ^ bit[5] ^ bit[7];

    cout << "\n1) R1 - Analyze bits at:";
    cout << "\n   R1 D3 D5 D7";
    cout << "\n   " << bit[1] << "  "
         << bit[3] << "  "
         << bit[5] << "  "
         << bit[7];

    cout << "\n   R1 = " << r1;

    int r2 = bit[2] ^ bit[3] ^ bit[6] ^ bit[7];

    cout << "\n\n2) R2 - Analyze bits at:";
    cout << "\n   R2 D3 D6 D7";
    cout << "\n   " << bit[2] << "  "
         << bit[3] << "  "
         << bit[6] << "  "
         << bit[7];

    cout << "\n   R2 = " << r2;

    int r4 = bit[4] ^ bit[5] ^ bit[6] ^ bit[7];

    cout << "\n\n3) R4 - Analyze bits at:";
    cout << "\n   R4 D5 D6 D7";
    cout << "\n   " << bit[4] << "  "
         << bit[5] << "  "
         << bit[6] << "  "
         << bit[7];

    cout << "\n   R4 = " << r4;

    int errorPosition = r4 * 4 + r2 * 2 + r1;

    cout << "\n\n--------------------------------";
    cout << "\nSyndrome = " << r4 << r2 << r1;
    cout << "\nDecimal equivalent = " << errorPosition;

    if (errorPosition == 0)
    {
        cout << "\n\nNo error detected.";
        cout << "\nReceived codeword is CORRECT.";
    }
    else
    {
        cout << "\nError is located at "
             << errorPosition << "th position.";

        // Invert the erroneous bit
        bit[errorPosition] = bit[errorPosition] ^ 1;

        string corrected = "";

        for (int pos = 7; pos >= 1; pos--)
        {
            corrected += char(bit[pos] + '0');
        }

        cout << "\n\nCorrected codeword is: "
             << corrected;
    }

    cout << endl;

    return 0;
}