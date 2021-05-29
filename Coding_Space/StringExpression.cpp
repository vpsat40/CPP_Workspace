/*
 * StringExpression.cpp
 *
 *  Created on: May 29, 2021
 *      Author: satish.vodapally
 */
/*
 * Have the function StringExpression(str) read the str parameter being passed which will contain the written
 * out version of the numbers 0-9 and the words "minus" or "plus" and convert the expression into an actual
 * final number written out as well.
 * For example: if str is "foursixminustwotwoplusonezero" then this converts to "46 - 22 + 10" which evaluates
 * to 34 and your program should return the final string threefour.
 * If your final answer is negative it should include the word "negative."
 *
 * Examples
 * Input: "onezeropluseight"
 * Output: oneeight
 *
 * Input: "oneminusoneone"
 * Output: negativeonezero
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void StringExpression(string str)
{
	unordered_map<string, char> charmap = { {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}, {"plus", '+'}, {"minus", '-'} };
	int oper = 0;
	string word, res;
	char sign = '@';
	int num =0;
	bool isNegative=false;

	for(char c : str)
	{
		word += c;

		auto itr = charmap.find(word);
		if(itr != charmap.end())
		{
			char c = itr->second ;
			cout << c << endl;

			//Identify if number or Sign is found
			if(isdigit(c))
			{
				//get num value
				num = num*10 + (c - '0');
			}
			else
			{
				// Encountered a sign
				if(sign == '+')
					oper = oper + num;
				else if(sign == '-')
					oper = oper - num;

				if(sign == '@')
				{
					oper = num;
				}
				sign = c;
				num =0;
			}
			word = "";
		}
	}
	if(sign == '+')
		oper = oper + num;
	else if(sign == '-')
		oper = oper - num;

	cout << "Value is " << oper << endl;

	if(oper < 0)
	{
		isNegative=true;
		oper = oper * -1;
	}

	while(oper > 0)
	{
		int rem = oper % 10;
		char ch = '0' + rem;
		oper = oper/10;

		cout << "Rem : " << rem << " & Char" << ch << endl;

		for(auto itrum = charmap.begin(); itrum != charmap.end(); itrum ++)
		{
			if(itrum->second == ch)
				res = itrum->first + res;
		}
	}

	if(isNegative)
		res = "negative" + res;

	cout << "Result in alpha numeric is " << res << endl;



}


int main(void)
{
	StringExpression("fiveonefiveminusfiveonezero");
	return 0;
}

