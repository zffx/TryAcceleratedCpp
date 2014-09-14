#include "Declaration.h"

#include <string>
#include <algorithm> //find_if()

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

vector<string> split(const string& sentence)
{
    vector<string> ret;
    string::size_type i = 0 , j = 0;
    while(i < sentence.size())
    {
        // ignore leading blanks
        while(i != sentence.size() && isspace(sentence[i])) //isspace!!
            ++i;
        j = i;

        // find end of next word
        while(j != sentence.size() && !isspace(sentence[j]))
            ++j;

        // if we found some nonwhitespace characters
        if(i != j )
        {
            ret.push_back(sentence.substr(i,j - i));
            i = j;
        }
    }
    return ret;
}

bool space(char c)
{
	return isspace(c);
}

bool notSpace(char c)
{
	return !space(c);
}

std::vector<std::string> splitAdvanced(const std::string &sentence)
{
	vector<string> ret;
	string::const_iterator i = sentence.begin(), j = sentence.begin();
	while(i != sentence.end())
	{
		// ignore leading blanks
		i = find_if(i,sentence.end(),notSpace);

		// find end of next word
		j = find_if(i, sentence.end(), space);

		// if we found some nonwhitespace characters
		if(i != sentence.end())
		{
			ret.push_back(string(i,j));
			i = j;
		}
	}
	return ret;
}

void splitAString()
{
    cout << "The sentence is: Welcome to my world!" << endl;
    string sentence = "  Welcome to my world! ";
    vector<string> afterSplit;
    //afterSplit = split(sentence);
    afterSplit = splitAdvanced(sentence);
    vector<string>::const_iterator constIter = afterSplit.begin();
    cout << "Here is the result after split:" << endl;
    while(constIter != afterSplit.end())
    {
        cout << *constIter << endl;
        ++constIter;
    }
}
