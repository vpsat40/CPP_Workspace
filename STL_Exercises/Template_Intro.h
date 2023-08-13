/*
 * ClassTemplate.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: satish.vodapally
 */

#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
T funcSquare(T x)
{
	return x*x;
}

template <typename CT>
class BoVector
{
	CT mArr[1000];
	int size;

public:
	BoVector(): size(0) {};

	void push(CT x)
	{
		mArr[size] = x;
		size++;
	}
	void print()
	{
		for(int i=0; i<size; i++)
			cout << mArr[i] << endl;
	}

	int getSize() { return size; }

	CT getElement(int i) { return mArr[i]; }

};


template <typename MT>
BoVector<MT> operator*(BoVector<MT>& rhs1, BoVector<MT>& rhs2)
{
	BoVector<MT> ret;
	for(int i=0; i < rhs1.getSize(); i++)
		ret.push(rhs1.getElement(i)*rhs2.getElement(i));

	return ret;
}

