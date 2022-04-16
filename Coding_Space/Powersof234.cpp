/*
 * Powersof234.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: satish.vodapally
 */

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

bool isPowerOfTwo1(int n)
{
	/*
	 * Most efficient way is bitwise
	 * Any power of 2 will have a leading 1 followed by 0's
	 * Ex 2 = b10, 4 = b100, 8 = b1000, 16 = b0001 0000
	 *
	 * So if n = 6 = b110 following logic evaluates to
	 * (n & (n-1)) = b110 & b011 non zero number
	 *
	 * if n = 16 = b0001 0000 following logic evaluates to
	 *  (n & (n-1)) = b0001 0000 & b0000 1111 a zero number
	 */

	if(n <= 0)
		return false;
	else
		return !(n & (n-1));
}

bool isPowerOfThree(int n)
{
	if ((n > 0) && (1162261467 % n) == 0)
		return true;
	else
		return false;
}

bool isPowerOfFour1(int n)
{
	// Brute force
	if(n <= 0)
		return false;

	while(n % 4 == 0)
		n = n / 4;

	if(n == 1)
		return true;
	else
		return false;

}

bool isPowerOfFour2(int n)
{
	set<int> fourPowers;
	set<int>::iterator pitr;
	int x = 1;

	// Insert all the powers of 4 into a set
	while(x > 0)
	{
		fourPowers.insert(x);
		//cout << "Inserted: " << x << endl;
		x = x * 4;
	}

	// Now check if n is present in the set;
	pitr = fourPowers.find(n);

	if(pitr != fourPowers.end())
		return true;
	else
		return false;

}

int Powersmain(void)
//int powersofnumbers()
{
	int x=0;

	/*
	 * Program to print powers
	int i = 0;

	while(x >= 0)
	{
		x = (int)pow(4, i++);
		cout << "4 pow " << i <<" = " << x << endl;
	}
	*/
	cout << " Enter number to check : " << endl;
	cin >> x ;

	if(isPowerOfTwo1(x))
		cout << x << " is a power of 2 " << endl;
	else
		cout << x << " is NOT a 2 power" << endl;

	if(isPowerOfThree(x))
			cout << x << " is a power of 3 " << endl;
		else
			cout << x << " is NOT a 3 power" << endl;

	if(isPowerOfFour1(x))
			cout << x << " is a power of 4 " << endl;
		else
			cout << x << " is NOT a 4 power" << endl;

	if(isPowerOfFour2(x))
			cout << x << " is a power of 4 " << endl;
		else
			cout << x << " is NOT a 4 power" << endl;

	return 0;
}

