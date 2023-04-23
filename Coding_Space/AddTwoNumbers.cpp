/*
 * AddTwoNumbers.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: satish.vodapally
 */
/*
 *
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
 * and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 * Example 2:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 * Example 3:
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * Explanation: 9999999+9999 = 10009998
 *
 * Constraints:
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have leading zeros.
 *
 */

#include <list>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:

	void printlist(list<int>& prntlst)
	{
		list<int>::const_iterator citr;

		for(citr = prntlst.begin(); citr != prntlst.end(); ++citr)
			cout << *citr << ", ";

		cout << endl;
	}

	list<int> addTwoNumbers(list<int>& l1, list<int>& l2)
	{
		int op1=0, op2=0, carry=0, sum=0;
		list<int> res;

		auto itr1 = l1.begin();
		auto itr2 = l2.begin();

		// Run a loop until both lists are exhausted
		while((itr1 != l1.end()) || (itr2 != l2.end()))
		{
			if(itr1 != l1.end())
			{
				op1 = *itr1;
				itr1++;
			}
			else 
				op1 = 0;
			
			if(itr2 != l2.end())
			{
				op2 = *itr2;
				itr2++;
			}
			else 
				op2 = 0;

			sum = op1 + op2 + carry;
			carry = sum/10;

			cout << "l1 = " << op1 << " l2 = " << op2 << endl;
			cout << "Sum - " << sum << endl;

			res.push_back(sum % 10);

		}

		if(carry)
		{
			res.push_back(carry);
			carry = 0;
		}

		return res;
	}

	list<int> addTwoNumbers_old(list<int>& l1, list<int>& l2)
		{
			reverse_iterator<list<int>::iterator> ritr1, ritr2;
			list<int> res;
			int a = 0, b =0, carry=0, sum = 0;

			//Initialize the reverse iterators
			ritr1 = l1.rbegin();
			ritr2 = l2.rbegin();

			while(ritr1 != l1.rend() || ritr2 != l2.rend())
			{
				if(ritr1 != l1.rend())
					a = *ritr1;
				else
					a = 0;

				if(ritr2 != l2.rend())
					b = *ritr2;
				else
					b = 0;

				sum = carry + a + b;
				carry = sum / 10;

				cout << "l1 = " << a << " l2 = " << b << endl;
				cout << "Sum - " << sum << endl;

				res.push_back(sum % 10);

				if(ritr1 != l1.rend())
					++ritr1;

				if(ritr2 != l2.rend())
					++ritr2;
			}
			return res;
		}
};


int main()
{
	list<int> result;
	list<int> l1 = {1, 2, 3, 4};
	list<int> l2 = {1, 9, 9, 8, 8, 7, 8};   // 2133978

	list<int> a1 = {2, 4, 3};
	list<int> a2 = {5, 6, 4};   // 7, 0, 8

	list<int> b1 = {0};
	list<int> b2 = {0};   // 0

	list<int> c1 = {9, 9, 9, 9, 9, 9, 9};   // 2133978
	list<int> c2 = {9, 9, 9, 9};

	Solution sol1;
	result = sol1.addTwoNumbers(l1, l2);

	cout << "----------------" << endl;
	sol1.printlist(l1);
	sol1.printlist(l2);
	cout << "----------------" << endl;
	sol1.printlist(result);
	cout << "----------------" << endl;

	result = sol1.addTwoNumbers(a1, a2);
	cout << "----------------" << endl;
	sol1.printlist(a1);
	sol1.printlist(a2);
	cout << "----------------" << endl;
	sol1.printlist(result);
	cout << "----------------" << endl;

	result = sol1.addTwoNumbers(b1, b2);
	cout << "----------------" << endl;
	sol1.printlist(b1);
	sol1.printlist(b2);
	cout << "----------------" << endl;
	sol1.printlist(result);
	cout << "----------------" << endl;

	result = sol1.addTwoNumbers(c1, c2);
	cout << "----------------" << endl;
	sol1.printlist(c1);
	sol1.printlist(c2);
	cout << "----------------" << endl;
	sol1.printlist(result);
	cout << "----------------" << endl;

	return 0;

}
