/*
    Description: For this challenge you will determine if numbers within an array follow an arithmetic or geometric sequence.
    Arith Geo II

    Have the function ArithGeoII(arr) take the array of numbers stored in arr
    and return the string "Arithmetic" if the sequence follows an arithmetic pattern
    or return "Geometric" if it follows a geometric pattern. If the sequence doesn't follow either pattern return -1.
    An arithmetic sequence is one where the difference between each of the numbers is consistent,
    where as in a geometric sequence, each term after the first is multiplied by some constant or common ratio.

    Arithmetic example: [2, 4, 6, 8] and Geometric example: [2, 6, 18, 54].
    Negative numbers may be entered as parameters, 0 will not be entered, and no array will contain all the same elements.

    Examples
    Input: {5,10,15}
    Output: Arithmetic

    Input: {2,4,16,24}
    Output: -1

    Tags: arraymath fundamentalssequences

*/

#include <iostream>
#include <string>
using namespace std;

string ArithGeo(int arr[], int arrLen)
{
    string res = "-1";
    bool isAP = true;
    bool isGP = true;
    int i=0;

    if(arrLen < 3)
        return res;

    int diff = arr[1]-arr[0];
    int mul = arr[1]/arr[0];
    //cout << "Diff - " << diff << "& Mul - " << mul << endl;

    while(i < arrLen-1)
    {
        if(arr[i+1] != (arr[i]+diff))
            isAP = false;

        if(arr[i+1] != (arr[i]*mul))
            isGP = false;

        i++;
    }

    if(isAP)
        res="Arithmetic";
    else if(isGP)
        res="Geometric";

    return res;
}

int main(void)
{
    int A[] = {5,10,15};
    int B[] = {2,4,6,8};
    int C[] = {2,6,18,54};
    int D[] = {2,4,16,24};

    //int arrLen = sizeof(A)/sizeof(A[1]);

    cout << "{5, 10, 15} is in - " << ArithGeo(A, sizeof(A)/sizeof(A[1])) << endl;
    cout << "{2, 4, 6, 8} is in - " << ArithGeo(B, sizeof(B)/sizeof(B[1])) << endl;
    cout << "{2,6,18,54} is in - " << ArithGeo(C, sizeof(C)/sizeof(C[1])) << endl;
    cout << "{2,4,16,24} is in - " << ArithGeo(D, sizeof(D)/sizeof(D[1])) << endl;

    return 0;
}
