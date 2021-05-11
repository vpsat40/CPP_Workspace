/*
 * IteratorEx.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: satish.vodapally
 */


#include "IteratorEx.h"
#include <iostream>


IteratorTypes::IteratorTypes()
{
	for(int i=1; i < 11; i++)
		mVec.push_back(i*10);

	for(int i=1; i < 11; i++)
	{
		mList.push_back(i * 10);
		mList.push_front(i * 5);
	}
}

void IteratorTypes::testRandomAccessIterator()
{
	vector<int>::iterator itr = mVec.begin();
	vector<int>::iterator itr1, itr2;

	itr = itr + 5;
	cout << "Itr + 5 = " << *itr <<endl;

	itr = itr - 4;
	cout << "Itr - 4 = " << *itr <<endl;

	itr = mVec.begin();
	itr1 = itr + 8;
	itr2 = itr + 2;

	cout << "Itr1 = " << *itr1 << " and Itr2 = " << *itr2 <<endl;
	if (itr1 < itr2)
		cout << "itr1 is less than itr2" << endl;
	else
		cout << "itr1 is greater than itr2" << endl;

	++itr;
	cout << "++itr = " << *itr << endl;
	--itr;
	cout << "--itr = " << *itr << endl;

	return;
}


void IteratorTypes::testBiDirectionalIter()
{
	list<int>::iterator itr;
	list<int>::reverse_iterator ritr;
	for(itr = mList.begin(); itr != mList.end(); ++itr)
		cout << *itr << " -> ";

	cout << "Printing the same list in reverse order " << endl;

	for(ritr = mList.rbegin(); ritr != mList.rend(); ++ritr)
		cout << *itr << " <- ";

	itr = mList.begin();
	itr = ++itr;

	cout << endl << *itr << endl;

}


void IteratorTypes::testReverseIterator()
{
	reverse_iterator<vector<int>::iterator> ritr;

	for(ritr = mVec.rbegin(); ritr != mVec.rend(); ++ritr)
		cout << *ritr << " -><- ";
}

//int main()
int itermain()
{
	IteratorTypes myIter;

	myIter.testRandomAccessIterator();
	cout << endl << "------------------------------" << endl;
	myIter.testBiDirectionalIter();
	cout << endl << "------------------------------" << endl;
	myIter.testReverseIterator();
	cout << endl << "------------------------------" << endl;

	return 0;
}
