/*
 * SimplePassword.cpp
 *
 *  Created on: May 30, 2021
 *      Author: satish.vodapally
 */
/*
 * Have the function SimplePassword(str) take the str parameter being passed and determine if it passes
 * as a valid password that follows the list of constraints:
 *
 * 1. It must have a capital letter.
 * 2. It must contain at least one number.
 * 3. It must contain a punctuation mark or mathematical symbol.
 * 4. It cannot have the word "password" in the string.
 * 5. It must be longer than 7 characters and shorter than 31 characters.
 *
 *
 * If all the above constraints are met within the string, the your program should return the string true,
 * otherwise your program should return the string false. For example: if str is "apple!M7" then your program should return "true".
 *
 * Examples
 *
 * Input: "passWord123!!!!"
 * Output: false
 *
 * Input: "turkey90AAA="
 * Output: true
 *
 * Tags
 * string manipulation
 * searching
 * hash table
 * back-end
 *
 */

#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

string SimplePassword(string str)
{
	string lower, res = "false";
	int pos = -1;
	bool hasUpper=false, hasNums=false, hasSym=false;
	unordered_set<char> charlist = {'+', '-', '/', '*', '=','@', '!', '#', '$', '%','&'};
	auto itr = charlist.begin();


	if(str.length() < 7 || str.length() > 31)
		return res;

	for(char c : str)
	{
		if(isalpha(c))
		{
			if(isupper(c))
			{
				hasUpper = true;
				c = tolower(c);
			}
		}
		else if(isdigit(c))
			hasNums = true;
		else
		{
			itr = charlist.find(c);
			if(itr != charlist.end())
				hasSym = true;
			else
			{
				//has invalid Symbol
				hasSym =  false;
				break;
			}
		}
		lower += c;
	}

	cout << lower << endl;

	if(lower.length() != str.length())
		return res;

	pos = lower.find("password");
	cout << "Position " << pos << endl;

	if(pos > -1)
		return res;

	if(hasUpper && hasSym && hasNums)
		res = "true";

	return res;

}


int main(void)
{
	cout << SimplePassword("apple!M7") << endl;
	cout << SimplePassword("turkey90AAA=") << endl;
	cout << SimplePassword("Start@u704") << endl;
	cout << SimplePassword("B11t6@p703") << endl;
	cout << SimplePassword("passWord123!!!!") << endl;

	return 0;
}

