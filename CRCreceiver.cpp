#include <iostream>
#include <string>
using namespace std;

int main()
{
    string codeword, divisor;

    cout << "Enter received codeword: ";
    cin >> codeword;

    cout << "Enter divisor: ";
    cin >> divisor;

    int codeLen = codeword.length();
    int divisorLen = divisor.length();

    string temp = codeword;

   
    for (int i = 0; i <= codeLen - divisorLen; i++)
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

   
    
    string remainder = temp.substr(codeLen - divisorLen + 1);

    cout << "\nCRC Remainder: " << remainder << endl;

    
    if (remainder.find('1') == string::npos)
        cout << "No Error in Received Data." << endl;
    else
        cout << "Error Detected in Received Data." << endl;

    return 0;
}