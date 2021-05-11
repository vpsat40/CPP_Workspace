/*
 * IteratorEx.h
 *
 *  Created on: Apr 21, 2021
 *      Author: satish.vodapally
 */

#ifndef ITERATOREX_H_
#define ITERATOREX_H_

#include <vector>
#include <list>

using namespace std;

class IteratorTypes
{
public:

	IteratorTypes();
	~IteratorTypes(){};


	vector<int> mVec;
	list<int> mList;
	/*
	 * Common Iterators
	 */
	void testRandomAccessIterator();
	void testBiDirectionalIter();
	void testForwardIter();
	void testInputIter();
	void testOutputIter();

	/*
	 * Advanced Iterators
	 */
	void testInsertIterator();
	void testStreamIterator();
	void testReverseIterator();

};



#endif /* ITERATOREX_H_ */
