/*
 * FindIntersection.cpp
 *
 *  Created on: Apr 25, 2021
 *      Author: satish.vodapally
 */

/*
 * Have the function FindIntersection(strArr) read the array of strings stored in strArr which will contain 2 elements:
 * the first element will represent a list of comma-separated numbers sorted in ascending order,
 * the second element will represent a second list of comma-separated numbers (also sorted).
 *
 * Your goal is to return a comma-separated string containing the numbers that occur in elements of strArr in sorted order.
 * If there is no intersection, return the string false.
 *
 * Examples
 * Input: {"1, 3, 4, 7, 13", "1, 2, 4, 13, 15"}
 * Output: 1,4,13
 *
 * Input: {"1, 3, 9, 10, 17, 18", "1, 4, 9, 10"}
 * Output: 1,9,10
 *
 * Tags
 * array free *
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


vector<int> split(const string& s, char delimiter)
{
	vector<int> inttokens;
	string token;
	istringstream token_stream(s);

	while(getline(token_stream, token, delimiter))
	{
		cout << token << " ";
		inttokens.push_back(stoi(token));
	}
	cout << endl;

	return inttokens;

}

string FindIntersection(string strArr[], int arrLength)
{
	vector<int> token1, token2;
	vector<int>::iterator itr;
	string res;
	char delimiter = ',';

	token1 = split(strArr[0], delimiter);
	token2 = split(strArr[1], delimiter);

	for(itr = token1.begin(); itr != token1.end(); ++itr)
	{
		cout << "Finding " << *itr << " in " << strArr[1] << endl;
		int value = *itr;

		if(find(token2.begin(), token2.end(), value) != token2.end())
		{
			//Value has been found. Convert it into char and insert it;
			cout << "\t" << value << " has been found..." << endl;

			res.append(to_string(value));
			res.append(",");
		}
		else
			cout << "\t\t" << value << " was NOT found..." << endl;

	}

	if(!res.empty())
	{
		res.pop_back();
	}
	else
		res = "false";

  // code goes here
  return res;

}


//int main(void)
int Intermain(void)
{
  // keep this function call here
  //string A[] = {"1, 3, 4, 7, 13", "1, 2, 4, 13, 15"};
  string A[] = {"1, 3, 9, 10, 17, 18", "1, 24, 29, 20"};
  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;

}


