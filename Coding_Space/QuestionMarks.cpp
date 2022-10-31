/*
 * QuestionMarks.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: satish.vodapally
 *
 *
 * Have the function QuestionsMarks(str) take the str string parameter, which will contain single digit numbers, letters
 * and question marks. Check if there are exactly 3 question marks between every pair of two numbers that add up to 10.
 * If so, then your program should return the string true, otherwise it should return the string false.
 * If there aren't any two numbers that add up to 10 in the string, then your program should return false as well.
 *
 * For example: if str is "arrb6???4xxbl5???eee5" then your program should return true because there are exactly 3
 * question marks between 6 and 4, and 3 question marks between 5 and 5 at the end of the string.
 *
 * Use the Parameter Testing feature in the box below to test your code with different arguments.
 */

#include <iostream>
#include <string>

using namespace std;

string QuestionsMarks(string str)
{
	int sum = 0;
	int countQ = 0;
	string res = "false";

	for(char c : str)
	{
		if(isdigit(c))
		{
			sum += (c - '0');
			cout << "Char - " << c << endl;
			cout << "Sum - " << sum << " QCount - " << countQ << endl;

			if((countQ == 3) && (sum == 10))
			{
				res = "true";
				break;
			}
			else
			{
				cout << "Reset count and reinstate sum..." << endl;
				countQ = 0;
				sum = (c - '0');
			}
		}
		else if(c == '?')
		{
			cout << "Ques - " << c << endl;
			countQ +=1;
		}
	}
  // code goes here
  return res;

}

int main(void)
{
  // keep this function call here
  cout << QuestionsMarks("aa6?9??stu?1");
  return 0;

  //"9???1???9??1???9"
  //For input "9???1???9??1???9" the output was incorrect. The correct output is false
  //For input "5??aaaaaaaaaaaaaaaaaaa?5?5" the output was incorrect. The correct output is false

}


