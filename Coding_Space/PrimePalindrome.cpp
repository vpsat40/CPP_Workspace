/*
 * PrimePalindrome.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: satish.vodapally
 */

#include <iostream>

using namespace std;

bool isPrime(int n)
{
	bool res = false;
	// 1 is neither prime nor composite
	// 2 is the smallest prime
	if(n<2)
		return res;

	if(n == 2)
		return true;

	//A prime number is only divisible by itself or 1
	//It does not have any factors

	for(int i=2; i <= n/2; i++)
	{
		if(n % i == 0)
		{
			return res;
		}
	}

	// n is prime
	cout << n << " is a Prime." << endl;
	res = true;
	return res;
}

bool isPalindrome(int n)
{
	bool res = false;
	int num = n;
	int rem = 0;

	cout << "Num = " << num << " Rem = " << rem << endl;

	while(num >= 1)
	{
		rem = (10 * rem) + num % 10;
		num /= 10;
		cout << "Num = " << num << " Rem = " << rem << endl;
	}

	if(rem == n)
		res = true;

	return res;
}

int main(void)
//int PrimePalindrome()
{
	int num = 1000;
	int x = num;

	while(true)
	{
		if(isPrime(x))
		{
			//X is a prime number
			//Check if its a palindrome as well
			if(isPalindrome(x))
			{
				//We have our nearest prime palindrome greater than or equal to n
				cout << x << " is the nearest prime palindrome greater than or equal to " << num << endl;
				break;
			}
		}

		x++;
	}

	return 0;

}



