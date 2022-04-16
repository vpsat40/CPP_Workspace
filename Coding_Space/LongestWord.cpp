/*
 * LongestWord.cpp
 *
 *  Created on: Apr 25, 2021
 *      Author: satish.vodapally
 */


/*
 *
 * Have the function LongestWord(sen) take the sen parameter being passed and return the longest word in the string.
 * If there are two or more words that are the same length, return the first word from the string with that length.
 * Ignore punctuation and assume sen will not be empty.
 *
 * Input: "fun&!! time"
 * Output: time
 *
 * Input: "I love dogs"
 * Output: love
 *
 * Words may also contain numbers, for example "Hello world123 567"
 */
#include <iostream>
#include <string>

using namespace std;

string LongestWord(string sen)
{
	string res = "";
	string word;

	for(char c : sen)
	{
		if(isalpha(c) || isdigit(c))
		{
			word += c;
		}
		else
		{
			cout << c <<" - is not AlphaNumeric" << endl;
			if(word.length() > res.length())
			{
				res = word;
				cout << " Inner Res - " << res << endl;
			}

			// Reset the word and start parsing for the new word.
			// We only need to return the first occurrance longest word.
			word = "";
		}
	}

	if(word.length() > res.length())
	{
		res = word;
		cout << " Outer Res - " << res << endl;
	}
  // code goes here
  return res;

}

int main(void)
{

  // keep this function call here
  cout << LongestWord("No fun&!! time tonight:((") << endl;
  return 0;

}

