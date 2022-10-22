/*
 * BracketMatcher.cpp
 *
 *  Created on: May 23, 2021
 *      Author: satish.vodapally
 *
 *  Title: Bracket Matcher
 *  Difficulty: Medium
 *  Solutions: 13580
 *  Maximum Score: 10
 *
 *  Description: For this challenge you will determine if the brackets in a string are correctly matched up.
 *
 *  Have the function BracketMatcher(str) take the str parameter being passed and return 1 if the brackets
 *  are correctly matched and each one is accounted for. Otherwise return 0.
 *
 *  For example: if str is "(hello (world))", then the output should be 1,
 *  but if str is "((hello (world))" the the output should be 0 because the brackets do not correctly match up.
 *  Only "(" and ")" will be used as brackets.
 *
 *  If str contains no brackets return 1.
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;


string BracketMatcher(string str)
{
	string res = "1";
	stack<char> bracketHold;

	for(char c : str)
	{
		if(c == '(')
		{
			//Place to push all '('
			bracketHold.push(c);
		}
		else if(c == ')')
		{
			//Check if stack is not empty
			if(!bracketHold.empty())
				bracketHold.pop();
			else
			{
				// We have an issue;
				res = "0";
				return res;
			}
		}
	}

	//string is parsed. Stack should be empty now
	if(!bracketHold.empty())
	{
		//Residue '(' are present in stack
		res = "0";
		return res;
	}
	return res;
}

int d2qmain(void)
{
  // keep this function call here
  cout << BracketMatcher("aa6?9??stu?1");
  return 0;

  //"9???1???9??1???9"
  //For input "9???1???9??1???9" the output was incorrect. The correct output is false
  //For input "5??aaaaaaaaaaaaaaaaaaa?5?5" the output was incorrect. The correct output is false

}


