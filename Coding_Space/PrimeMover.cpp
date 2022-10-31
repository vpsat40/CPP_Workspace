/*
    Prime Mover
    Have the function PrimeMover(num) return the numth prime number. The range will be from 1 to 10^4.
    For example: if num is 16 the output should be 53 as 53 is the 16th prime number.

    Examples
    Input: 9
    Output: 23

    Input: 100
    Output: 541

    Tags: math fundamentals, prime numbers

*/

#include <iostream>
using namespace std;

bool isPrimee(int num)
{
    bool res = false;

    if(num == 1)
        return res; // 1 is neither prime nor composite
    else if(num == 2)
    {
        // 2 is a prime
        res = true;
        return res;
    }

    for(int i=2; i <= num/2; i++)
    {
        if(num % i == 0)
            return res;
    }
    res = true;

    return res;
}

int PrimeMover(int num)
{
    int count = 1;
    if(num == count)
        return 2;

    int checkforPrime = 2;

    while(count < num)
    {
        checkforPrime++;

        if(isPrimee(checkforPrime))
            count++;
    }
    return checkforPrime;

}

int main(void)
{
    // Prime Mover from CoderByte

    cout << "Prime Mover 9 - " << PrimeMover(9) << endl;
    cout << "Prime Mover 18 - " << PrimeMover(18) << endl;
    cout << "Prime Mover 27 - " << PrimeMover(27) << endl;
    cout << "Prime Mover 36 - " << PrimeMover(36) << endl;
    cout << "Prime Mover 45 - " << PrimeMover(45) << endl;
    cout << "Prime Mover 100 - " << PrimeMover(100) << endl;

    return 0;
}
