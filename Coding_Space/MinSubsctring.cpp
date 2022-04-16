/*
 * MinSubsctring.cpp
 *
 *  Created on: Apr 25, 2021
 *      Author: satish.vodapally
 */


/*
 *
 * Min Window Substring
 *
 * Have the function MinWindowSubstring(strArr) take the array of strings stored in strArr, which will contain only two strings,
 * 		the first parameter being the string N and
 * 		the second parameter being a string K of some characters,
 *
 * and your goal is to determine the smallest substring of N that contains all the characters in K.
 *
 * For example: if strArr is ["aaabaaddae", "aed"] then the smallest substring of N that contains the characters a, e, and d
 * is "dae" located at the end of the string.
 * So for this example your program should return the string dae.
 *
 * Another example: if strArr is ["aabdccdbcacd", "aad"] then the smallest substring of N that contains all of the characters in K
 * is "aabd" which is located at the beginning of the string.
 *
 * Both parameters will be strings ranging in length from 1 to 50 characters and
 * all of K's characters will exist somewhere in the string N.
 * Both strings will only contains lowercase alphabetic characters.
 *
 *
 */


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//
bool isCovered(unordered_map<char, int>& f1, unordered_map<char, int>& f2)
{
	// For loop traversing through hash table of K
	for (unordered_map<char, int>::iterator iter=f2.begin(); iter!=f2.end(); iter++)
	{
		cout << "In string K: " << iter->first << " value is " << iter->second << endl;
		cout << "In string N: " << f1[iter->first] << endl << "------------------" << endl;
		if (f1[iter->first] < iter->second)
		{
			return false;
		}
	}

	return true;
}

string MinWindowSubstring(string strArr[], int arrLength)
{
	string N = strArr[0];
	string K = strArr[1];

	unordered_map<char, int> freq;

	//Created a hash table for string K and stored the occurrence
	for (int i=0, length=K.length(); i<length; i++)
	{
		freq[K[i]]++;
	}

	int idx = 0;
	int shortest = N.length();
	unordered_map<char, int> f;

	// Two pointer technique to search within string N
	// start == startidx, end = endidx; length = string length
	for (int start=0, end=0, length=N.length(); end<length; end++)
	{
		//Creating hash table for string N
		f[N[end]]++;

		cout << "-" << N[end] << "-" << endl;

		while (isCovered(f, freq))
		{
			if (shortest > end-start+1)
			{
				shortest = end-start+1;
				idx = start;
			}

			cout << "Start = " << start <<" End = " << end << " Shortest = " << shortest <<endl;
			cout << "N[start] = " << N[start] << "\t" << "Removing it from hash and decrementing." << endl;

			f[N[start]]--;
			start++;
		}
	}
	// code goes here
	return N.substr(idx, shortest);
}

int Minmain(void) {

//int main(void) {

  // keep this function call here
  string A[] = {"bacffa", "aff"};
  int arrLength = sizeof(A) / sizeof(*A);
  cout << MinWindowSubstring(A, arrLength);
  return 0;

}
