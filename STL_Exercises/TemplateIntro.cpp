/*
 * TemplateIntro.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: satish.vodapally
 */


#include "ClassTemplate.h"

//Function Template example
template <typename T>

T squareFn(T x)
{
	return x*x;
}


//This was main function
int templateCheck() { // Code bloat

	cout << squareFn<int>(5) << endl;
	cout << squareFn<double>(5.5) << endl;
	cout << squareFn<float>(3.333) << endl << endl;


	BoVector<int> bv, bv1;

	bv.push(2);
	bv.push(4);
	bv.push(6);
	bv.push(9);

	bv.print();

	cout << "Print squared BV: " << endl;
	bv1 = squareFn(bv);
	bv1.print();

	return 0;
}

