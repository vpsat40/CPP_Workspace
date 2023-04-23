/*
 * StringStreamEx.cpp
 *
 *  Created on: May 12, 2021
 *      Author: satish.vodapally
 */

#include <iostream>
#include <sstream>

using namespace std;

/*
 * convert Decimal to Hexadecimal using string stream
 */

void convertToHex(const int& num, string& res)
{
	stringstream my_ss;

	my_ss << hex << num;
	res = my_ss.str();

	return;
}

int main()
{
	int  decimal = 55;
	string output;

	//cout << "Enter decimal number" << endl;
	//cin >> decimal;

	convertToHex(decimal, output);
	cout << "Hex Num : - " << output;
	return 0;

}
