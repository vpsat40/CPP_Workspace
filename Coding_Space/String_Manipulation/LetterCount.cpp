/*
    Title: Letter Count
    Difficulty: Medium
    Solutions: 8676
    Maximum Score: 10

    Description: For this challenge you will determine which word has the greatest number of repeated letters.

    Have the function LetterCount(str) take the str parameter being passed and return the
    first word with the greatest number of repeated letters.

    For example: "Today, is the greatest day ever!" should return greatest because it has 2 e's (and 2 t's)
    and it comes before ever which also has 2 e's. If there are no words with repeating letters return -1.

    Words will be separated by spaces.

    Examples
    Input: "Hello apple pie"
    Output: Hello

    Input: "No words"
    Output: -1

    Tags: Searching hash table

*/

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <map>

using namespace std;

string LetterCount(string str)
{
    string res = "-1";
    string word;
    int reps = 1;
    stringstream ss(str);  // Used to break the string sentence into individual words
    stringstream ss1(str);
    map<string, unordered_map<char,int>> wordList;

    // For each word, identify the number of occurances using a hash map.
    while(ss >> word)
    {
        unordered_map<char,int> letterCnt;

        for(char c : word)
        {
            letterCnt[c]++;
            cout << "Char -" << c << " & Count = " << letterCnt[c] << endl;
        }
        cout << "Hash size for word - " << word << " - is " << letterCnt.size() << endl << endl;
        wordList.insert(make_pair(word, letterCnt));
    }

    while(ss1 >> word)
    {
        unordered_map<char,int> letterCnt;
        auto it = wordList.find(word);
        if(it != wordList.end())
            letterCnt = it->second;

        cout << "In " << word << " - you have " << endl;

        for(char c : word)
        {
            if(letterCnt[c] > reps)
            {
                reps = letterCnt[c];
                res = word;
                cout << c << " - " << letterCnt[c] << endl;
                //letterCnt[c] = 0;
            }
        }
    }

    return res;
}

int main(void)
{

    string str1 = "Hello apple pie!";
    string str2 = "No words";
    string str3 = "Today, is the greatest day ever!";

    cout << "Letter Count str1" << endl << LetterCount(str1) << endl << endl;
    cout << "Letter Count str2" << endl << LetterCount(str2) << endl << endl;
    cout << "Letter Count str3" << endl << LetterCount(str3) << endl << endl;

    return 0;
}
