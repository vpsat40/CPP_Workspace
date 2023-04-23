/*
    Description: For this challenge you will be converting a number from binary to decimal.
    Binary Converter: Have the function BinaryConverter(str) return the decimal form of the binary value.
    For example: if 101 is passed return 5, or if 1000 is passed return 8.

    Examples

    Input: "100101"
    Output: 37

    Input: "011"
    Output: 3

    Tags: math fundamentals

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int BinaryConverter(string str)
{
    int res = 0;
    int base = 0;

    for(int i=(str.size() -1); i >= 0; i--, base++)
    {
        if(str[i] == '1')
            res += pow(2, base);
    }

    return res;
}

int main(void)
{
    cout << "Binary Converter Program " << endl;
    cout << BinaryConverter("100101") << endl;
    cout << BinaryConverter("101") << endl;
    cout << BinaryConverter("1000") << endl;
    cout << BinaryConverter("011") << endl;

    return 0;
}
