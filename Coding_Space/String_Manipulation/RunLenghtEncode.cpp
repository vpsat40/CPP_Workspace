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
        // Termination Condition
        retString += '0' + count;
        retString += str[i];
        return;
    }
    else
    {
        // String left to process
        if(str[i] == str[i+1])
        {
            count++;
            #if 1
            RunLengthRecursive(str.substr((i+1), str.size()-1));
            #else
            // Either invocation of string.substr can be used. In the following case the 
            // remainder of string will be taken.
            RunLengthRecursive(str.substr(i+1));
            #endif
        }
        else
        {
            retString += '0'+ count;
            retString += str[i];
            count = 1;
            #if 1
            RunLengthRecursive(str.substr((i+1), str.size()-1));
            #else
            // Either invocation of string.substr can be used. In the following case the 
            // remainder of string will be taken.
            RunLengthRecursive(str.substr(i+1));
            #endif
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
            // Encountered the same alphabet
            cnt++;
        }
        else
        {
            // You've encountered a new alphabet
            res += '0'+ cnt;
            res += str[i];
            cnt = 1;
        }
        i++;
    }

    return res;

}

int main(void)
{
  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set
     it equal to the stdin to test your code with arrays. */

  string B = {"aabbcde"};
  string A = {"wwwbbbw"};
  cout << "Runlength - Pass through execution - "<< A << " = " << RunLength(A) << endl;

  RunLengthRecursive(B);
  cout << "Runlength - Recursive execution - "<< B << " = " << retString << endl;

  return 0;

}
