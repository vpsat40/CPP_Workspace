/**
 * Prime Time
 * 
 * Have the function PrimeTime(num) take the num parameter being passed and 
 * return the string true if the parameter is a prime number, otherwise return the string false. 
 * The range will be between 1 and 2^16.
 * 
 * Examples
 * Input: 19
 * Output: true
 * 
 * Input: 110
 * Output: false
 * 
 * Tags
 * math fundamentals, prime numbers
 * */

#include <iostream>
using namespace std;

string Primetime(int n)
{
    string res = "false";
    
    if(n < 2)
        return res;
    else if(n == 2)
    {
        res = "true";
        return res;
    }
    else
    {
        for(int i = 2; i < n/2; i++)
        {
            if(n % i == 0)
                return res;
        }
    }
    res = "true";

    return res;   
}

int main(void)
{
    cout << Primetime(3) << endl;
    cout << Primetime(19) << endl;
    cout << Primetime(((2^10)+9)) << endl;

    return 0;
}