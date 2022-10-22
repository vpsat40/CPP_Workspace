/*
Various ways of reversing a string

*/
#include <iostream>
#include <string>
using namespace std;

// Reverse string by swapping characters from two corners
void ReverseBySwap(string &str)
{
    int len = str.length(); //you can use str.size() as well

    for(int i=0; i < len/2; i++)
        swap(str[i], str[len-1-i]);

    cout << "ReverseBySwap = " << str << endl;
}

// Using last to first approach
void ReverseLast2First(string str)
{
    //Using while loop
    int len = str.size();
    int n = len-1;
    int i = 0;

    while(i <= n)
    {
        swap(str[i], str[n]);
        i++;
        n--;
    }

    cout << "ReverseLast2First(Using while loop) = " << str << endl;

    string reversed;
    i = 0;
    for(i = (len - 1); i >= 0; i--)
        reversed += str[i];

    cout << "ReverseLast2First(Using for loop) = " << reversed << endl;
}

int SR_main(void)
{
    string A = "noelseesleon";
    string B = "AwarattarawA";
    string C = "AnneivotemorecarsracerometoviennA";

    cout << "Palindrom Two" << endl << endl;

    ReverseBySwap(A);

    ReverseLast2First(B);

    //PalindromeTwo(C);
    //cout << "Result C is " << res << endl;

    return 0;
}
