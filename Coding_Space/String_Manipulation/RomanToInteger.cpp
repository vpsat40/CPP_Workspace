/*
 * RomanToInteger.cpp
 *
 *  Created on: Apr 11, 2022
 *      Author: satish.vodapally
 */


/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, 2 is written as II in Roman numeral, just two one's added together.
 * 12 is written as XII, which is simply X + II.
 * The number 27 is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
 * Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 *
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer.
 * Example 1:
 *
 * Input: s = "III"
 * Output: 3
 * Explanation: III = 3.
 * Example 2:
 *
 * Input: s = "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * Example 3:
 *
 * Input: s = "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 *
 * Constraints:
 *
 * 1 <= s.length <= 15
 * s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 * It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string str)
{
    int num = 0;
    string searchStr;
    int idx = 0;
    unordered_map<string, int> romeNumMap = {
                                {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M" ,1000},
                                {"IV", 4}, {"IX", 9},
                                {"XL", 40}, {"XC", 90},
                                {"CD", 400}, {"CM", 900} };

    while(idx < (int)str.size())
    {

        searchStr += str[idx];
        searchStr += str[idx+1];
        cout << "SearchStr = " << searchStr << endl;

        auto itr = romeNumMap.find(searchStr); //MC -- CM -- XC --IV
        if(itr != romeNumMap.end())
        {
            cout << "SearchStr" << searchStr << "- Value = " << itr->second << endl;
            num = num + itr->second;
            idx++;
        }
        else
        {
            searchStr.clear();
            searchStr = str[idx];
            cout << "Curr char" << searchStr << endl;
            auto itr2 = romeNumMap.find(searchStr); //M
            if(itr2 != romeNumMap.end())
            {
                cout << "CurrChar" << str[idx] << "- Value = " << itr2->second << endl;
                num += itr2->second;
            }
            else
            {
                cout << "Invalid symbol encountered" << endl;
                return -1;
            }
        }
        idx++;
        searchStr.clear();
    }


    return num;
}
int getInteger(char c)
{
    switch(c)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return -1;
    }
}
int otherRomanToInt(string s)
{
    int n = s.size() , result = 0 , current , next , i = 0;
    while(i < n)
    {
        if(i == n - 1)
        {
            result += getInteger(s[i]);
            return result;
        }
        current = getInteger(s[i]) , next = getInteger(s[i + 1]);
        if(current >= next)
            result += current , i++;
        else
            result += next - current , i += 2;
    }
    return result;
}

int RI_main(void)
{
    int res = 0;

	res = otherRomanToInt("MCMXCIV");
	cout << "Result = " << res << endl;

    cout << "---------------------------------------" << endl;

	res = otherRomanToInt("LVIII");
	cout << "Result = " << res << endl;

	cout << "---------------------------------------" << endl;

	res = otherRomanToInt("III");
	cout << "Result = " << res << endl;
	return 0;
}
