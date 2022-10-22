/*
    Title: Palindrome Two     Difficulty: Medium    Solutions: 13431    Maximum Score: 10

    For this challenge you will be determining if a string is a palindrome.
    Have the function PalindromeTwo(str) take the str parameter being passed and return the string true if the parameter is a palindrome,
    (the string is the same forward as it is backward) otherwise return the string false.

    The parameter entered may have punctuation and symbols but they should not affect whether the string is in fact a palindrome.

    For example: "Anne, I vote more cars race Rome-to-Vienna" should return true.

    Examples
    Input: "Noel - sees Leon"
    Output: true

    Input: "A war at Tarawa!"
    Output: true

    Tags: string manipulation searching

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


string PalindromeTwo(string str)
{
    string res = "false";
    string filter, reversed;

    for(char c : str)
    {
        if(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
            filter += tolower(c);   //Found an alphabet. Could be cap or lower. Get it to lowercase
        else    //Found a special character or space. Omit it.
        {}
        cout << c;
    }

    reversed = string(filter.rbegin(), filter.rend());
    cout << endl << filter << " and " << reversed << endl;

    if(filter.compare(reversed) == 0)
        res = "true";

    return res;
}

int PT_main(void)
{
    string A = "Noel - sees Leon";
    string B = "A war at Tarawa!";
    string C = "Anne, I vote more cars race Rome-to-Vienna";
    string res;

    cout << "Palindrom Two" << endl << endl;

    res = PalindromeTwo(A);
    cout << "Result A is " << res << endl;
    res = PalindromeTwo(B);
    cout << "Result B is " << res << endl;
    res = PalindromeTwo(C);
    cout << "Result C is " << res << endl;

    return 0;
}
