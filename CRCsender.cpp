#include <iostream>
#include <string>
using namespace std;

int main()
{
    string codeword, divisor;

    cout << "Enter codeword: ";
    cin >> codeword;

    cout << "Enter divisor: ";
    cin >> divisor;

    int codewordLen = codeword.length();
    int divisorLen = divisor.length();

    string temp = codeword + string(divisorLen - 1, '0');

    for (int i = 0; i <= temp.length() - divisorLen; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < divisorLen; j++)
            {
                temp[i + j] =
                    (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }


    string remainder = temp.substr(codewordLen, divisorLen - 1);

    string data = codeword + remainder;

    cout << "\nCRC Remainder: " << remainder << endl;
    cout << "Transmitted Codeword: " << data << endl;

    return 0;
}