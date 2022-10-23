/*
 * Title: Division Difficulty: Medium Solutions: 11761 Maximum Score: 10
 * Description: For this challenge you will determine the Greatest Common Factor between two numbers.
 * 
 * Have the function Division(num1,num2) take both parameters being passed and return the Greatest Common Factor. 
 * That is, return the greatest number that evenly goes into both numbers with no remainder. 
 * For example: 12 and 16 both are divisible by 1, 2, and 4 so the output should be 4. The range for both parameters will be from 1 to 10^3.
 * 
 * Examples
 * Input: 7 & num2 = 3
 * Output: 1
 * 
 * Input: 36 & num2 = 54
 * Output: 18
 * 
 * Tags: math fundamentals algebra
 * Optimal solution using Euclidean alogrithm check 
 * https://brilliant.org/wiki/greatest-common-divisor/#:~:text=The%20greatest%20common%20divisor%20(GCD,number%20that%20divides%20them%20both.
*/
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

int Division_GCF_GCD_optimal(int num1, int num2)
{
    while (num1 != num2)
    {
        if(num1 > num2)
        {
            // Calculate the difference of num1 and num2 and store it in num 1
            num1 = num1 - num2;
        }
        else
        {
            // Calculate the difference of num1 and num2 and store it in num 2
            num2 = num2 - num1;
        }
    }

    return num1;
}

int Division_GCF_GCD(int num1, int num2)
{
    if(num1 == num2)
        return num1;
    
    
}

int main(void)
{
    auto t_start = chrono::high_resolution_clock::now();

    cout << "Result - " << Division_GCF_GCD_optimal(7, 2) << endl;
    cout << "Result - " << Division_GCF_GCD_optimal(36, 54) << endl;

    auto t_end = chrono::high_resolution_clock::now();
    double elapsed_time_ms = chrono::duration<double, milli>(t_end - t_start).count();    
    cout << "Time in ms :" << elapsed_time_ms << endl;


    cout << "Result - " << Division_GCF_GCD(7, 2) << endl;
    cout << "Result - " << Division_GCF_GCD(7, 2) << endl;
    return 0;
}