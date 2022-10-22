/*

    Title: Array Addition [Difficulty: Medium] [Solutions: 11877] [Maximum Score: 10]

    Description: For this challenge you will determine if numbers in an array can add up to a certain number in the array.
    Have the function ArrayAddition(arr) take the array of numbers stored in arr and return the string true
    if any combination of numbers in the array (excluding the largest number) can be added up to equal the largest number in the array,
    otherwise return the string false.

    For example: if arr contains [4, 6, 23, 10, 1, 3] the output should return true because 4 + 6 + 10 + 3 = 23.
    The array will not be empty, will not contain all the same elements, and may contain negative numbers.

    Examples:

    Input: {5,7,16,1,2}
    Output: false

    Input: {3,5,-1,8,12}  //12, 8, 5, 3, -1
    Output: true

    Tags: arraysearching, dynamic programming, Google, Microsoft, Facebook, Amazon, recursion

*/

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

/*int checkNum(int nums[], int target, int arrLen)
{

}*/

int ArrayAddition(int nums[], int arrLen)
{
    int res = 0;
    int sum = 0;

    //Sort elements in the array in ascending order using sort function

    sort(nums, nums+arrLen, greater<int>());
    int target = nums[0];
    cout << nums[0] << endl;
    cout << "Arr Len = " << arrLen << "& Target Num = " << target << endl;

    // Calculate the sum of remaining elements

    sum = accumulate(nums+1, nums+arrLen, sum);
    cout << "Sum of elements = " << sum << endl;

    if(sum == target)
    {
        res = 1;
        return res;
    }

    for(int i=0; i< arrLen; i++)
    {
        if(sum - nums[i] == target)
        {
            res = 1;
            return res;
        }
    }
    return res;
}


int AA_main(void)
{
    int A[] = {4, 6, 23, 10, 1, 3};
    int B[] = {3,5,-1,8,12};
    int C[] = {5,7,16,1,2};
    int res = 0;
    int arrLen = 0;

    arrLen = sizeof(A)/sizeof(A[1]);
    res = ArrayAddition(A, arrLen);
    cout << "A Outcome = " << res << endl;

    arrLen = sizeof(B)/sizeof(B[1]);
    res = ArrayAddition(B, arrLen);
    cout << "B Outcome = " << res << endl;

    arrLen = sizeof(C)/sizeof(C[1]);
    res = ArrayAddition(C, arrLen);
    cout << "C Outcome = " << res << endl;

    return res;
}
