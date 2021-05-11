/*
 * UnorderedMapEx.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: satish.vodapally
 */

/*
 * A practical problem based on unordered_map – given a string of words, find frequencies of individual words.
 *
 * Input :  str = "geeks for geeks geeks quiz practice qa for";
 * Output : Frequencies of individual words are
 *
 * (practice, 1)
 * (for, 2)
 * (qa, 1)
 * (quiz, 1)
 * (geeks, 3)
 *
 */


#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

void funcUnorderedMap1()
{
	// Function to demonstrate functionality of unordered_map

	// Declaring umap to be of <string, int> type key will be of string type and mapped value will be of int type
	unordered_map<string, int> umap;

	//Adding elements using [] operator to umap;
	umap["satish"] = 1979;
	umap["sowmya"] = 1987;
	umap["Sameeksha"] = 2013;
	umap["Samanvita"] = 2019;

	for(auto x : umap)
		cout << x.first << "'s birth year is " << x.second << endl;
}

void funcUnorderedMap2()
{
	// Function2 to demonstrate functionality of unordered_map

	// Declaring umap to be of <string, double> type
	// key = string type and
	// mapped value = double type
	unordered_map<string, double> umVals;

	umVals["Pi"] = 3.14;
	umVals["g"] = 9.8;
	umVals["root3"] = 1.732;

	umVals.insert({"root2", 1.414});
	umVals.insert(make_pair("log10", 2.302));

	string items[] = {"Pi", "g", "root2", "root3", "root4", "lambda", "log10"};

	for(string key : items)
	{
		if(umVals.find(key) != umVals.end())
			cout << "Found - " << key << endl;
		else
			cout << key << " NOT found. Sorry! " << endl;
	}

	//Using unordered_map iterator to traverse
	unordered_map<string, double>::iterator itr;
	cout << "Printing all elements " << endl;

	for(itr = umVals.begin(); itr != umVals.end(); ++itr)
		cout << itr->first << " value is " << itr->second << endl;
}

void printFrequencies(const string& str)
{
	unordered_map<string, int> wordCount;

	//Break input sentence in str to words
	stringstream ss(str);   //initialize ss with input sentence
	string word;
	//int cnt = 0;

	/*while( ss >> word)
	{
		cnt += 1;
		cout << word << " is " << cnt << " word" <<endl;
	}*/

	while( ss >> word)
		wordCount[word]++;

	unordered_map<string, int>::iterator uitr;
	for(uitr = wordCount.begin(); uitr != wordCount.end(); ++uitr)
		cout << "( " << uitr->first << ", " << uitr->second << " )" <<endl;
}


int main()
{
	// Functions to demonstrate functionality of unordered_map
	//funcUnorderedMap1();
	//funcUnorderedMap2();

	string inp = "geeks for geeks geeks quiz part one practice qa for geeks week 1";
	printFrequencies(inp);
}


