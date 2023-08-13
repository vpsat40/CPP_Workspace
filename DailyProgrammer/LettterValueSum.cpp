/**
 * @file LettterValueSum.cpp
 * @author Satish V
 * @brief 
 * @version 0.1
 * @date 2023-07-20
 * 
 * Challenge #399
 * Assign every lower case letter a value, from 1 for 'a' to 26 for 'z'. Given a string of 
 * lower case letters, find the sum of the values of the letters in the string.
 * 
 * lettersum("") => 0
 * lettersum("a") => 1
 * lettersum("z") => 26
 * lettersum("cab") => 6
 * lettersum("excellent") => 100
 * lettersum("microspectrophotometries") => 317
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int lettersum(string letters)
{
    int sum = 0;

    for (char ch : letters)
    {
        if(isalpha(ch))
        {
            if(isupper(ch))
            {
                ch = tolower(ch);
            }

            sum += ch-'`';            
        }
    }

    return sum;
}

int main()
{
    string t1 = "";
    string t2 = "a";
    string t3 = "z";
    string t4 = "cab";
    string t5 = "excellent";
    string t6 = "microspectrophotometries";

    cout << "Sum of Letter in string t1 is " << lettersum(t1) << endl;
    cout << "Sum of Letter in string t2 is " << lettersum(t2) << endl;
    cout << "Sum of Letter in string t3 is " << lettersum(t3) << endl;
    cout << "Sum of Letter in string t4 is " << lettersum(t4) << endl;
    cout << "Sum of Letter in string t5 is " << lettersum(t5) << endl;
    cout << "Sum of Letter in string t6 is " << lettersum(t6) << endl;

    return 0;
}
