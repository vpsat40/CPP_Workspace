/*
    Run Length
    Have the function RunLength(str) take the str parameter being passed and return a compressed version of the string
    using the Run-length encoding algorithm.

    This algorithm works by taking the occurrence of each repeating character and outputting that
    number along with a single character of the repeating sequence.

    For example: "wwwggopp" would return 3w2g1o2p. The string will not contain any numbers, punctuation, or symbols.

    Examples:
    Input: "aabbcde"
    Output: 2a2b1c1d1e

    Input: "wwwbbbw"
    Output: 3w3b1w

    Tags
    string manipulation encoding recursion
 */

#include <iostream>
#include <string>

using namespace std;

int count =1;
string retString;


void RunLengthRecursive(string str)
{
    int i = 0;

    if(str.size() <= 1)
    {
        retString += '0' + count;
        retString += str[i];
        return;
    }
    else
    {
        if(str[i] == str[i+1])
        {
            count++;
            //RunLengthRecursive(str[i+1]);
            RunLengthRecursive(str.substr((i+1), str.size()));
        }
        else
        {
            retString += '0'+ count;
            retString += str[i];
            count = 1;
            //RunLengthRecursive(str[i+1]);
            RunLengthRecursive(str.substr((i+1), str.size()));
        }
    }
}

string RunLength(string str)
{
    string res;
    int i =0;
    int cnt = 1;

    while (i < (int)str.size())
    {
        if(str[i] == str[i+1])
        {
            cnt++;
        }
        else
        {
            res += '0'+ cnt;
            res += str[i];
            cnt = 1;
        }
        i++;
    }

    return res;

}

int RL_main(void)
{
  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set
     it equal to the stdin to test your code with arrays. */

  string B = {"aabbcde"};
  string A = {"wwwbbbw"};
  cout << RunLength(A) << endl;

  RunLengthRecursive(B);
  cout << retString << endl;

  return 0;

}
