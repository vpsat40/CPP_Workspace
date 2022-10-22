
/*
Tree Constructor
    Have the function TreeConstructor(strArr) take the array of strings stored in strArr,
    which will contain pairs of integers in the following format:
    (i1,i2), where i1 represents a child node in a tree
    and the second integer i2 signifies that it is the parent of i1.

    For example: if strArr is ["(1,2)", "(2,4)", "(7,2)"], then this forms the following tree:

            4
           /
          2
        /   \
       1     7

    which you can see forms a proper binary tree.

    Your program should, in this case, return the string true because a valid binary tree can be formed.
    If a proper binary tree cannot be formed with the integer pairs, then return the string false.
    All of the integers within the tree will be unique, which means there can only be one node in the tree with the given integer value.

    Examples:

    Input: {"(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"}
    Output: true

    Input: {"(1,2)", "(3,2)", "(2,12)", "(5,2)"}
    Output: false

    Tags: arraybinary treedata engineerGoogleFacebookfreevideo

*/

// COULD NOT UNDERSTAND //

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, pair<int,int> > nodeType;

pair<int, int> parseString(string strToParse)
{
  int commaPos = strToParse.find(",");
  int child = stoi(strToParse.substr(1, commaPos));
  int parent = stoi(strToParse.substr(commaPos+1, strToParse.size()));

  return make_pair(child, parent);
}

string TreeConstructor(string strArr[], int arrLength) {

  vector<nodeType> nodeList;

  for(int i = 0; i < arrLength; i++)
  {
    pair<int,int> newTuple = parseString(strArr[i]);

    bool isParentInList = false;
    bool isChildInList = false;
    int nNodesInList = nodeList.size();

    int newNodeParent = newTuple.second;
    int newNodeChild = newTuple.first;

    for (int j = 0; j < nNodesInList; j++)
    {
      int loopNodeParent = nodeList[j].first;

      pair<int,int> loopNodeNumLinks = nodeList[j].second;

      if (loopNodeParent == newNodeParent)
      {
        isParentInList = true;
        if (loopNodeNumLinks.second >= 2)
          return "false";
        else
          nodeList[j].second.second++;
      }

      if (loopNodeParent == newNodeChild)
      {
        isChildInList = true;
        if (loopNodeNumLinks.first >= 1)
          return "false";
        else
          nodeList[j].second.first++;
      }
    }
    if (!isChildInList)
    {
      nodeType newNode1;
      newNode1.first = newNodeChild;
      newNode1.second = make_pair(1, 0);
      nodeList.push_back(newNode1);
    }

    if (!isParentInList)
    {
      nodeType newNode2;
      newNode2.first = newNodeParent;
      newNode2.second = make_pair(0, 1);
      nodeList.push_back(newNode2);
    }
  }

  return "true";
}

int CNU_TCmain(void) {

  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set
     it equal to the stdin to test your code with arrays. */

  string A[] = {"(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"};
  int arrLength = sizeof(A) / sizeof(*A);
  cout << TreeConstructor(A, arrLength);


  return 0;

}
