#include "Declaration.h"
#include <string>

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
        if(sentence.at(i) != ' ')
        {
            while(j < sentence.size() && sentence.at(j) == ' ')
            {
                ++j;
            }
            while(j < sentence.size() && sentence.at(j)!= ' ')
            {
                ++j;
            }
            ret.push_back(sentence.substr(i,j - i));
            i = j;
        }
        else
        {
            ++i;
        }
    }
    return ret;
}

void splitAString()
{
    cout << "Input your string with some space to split" << endl;
    string sentence = "  Welcome to my world! ";
    //std::getline(std::cin,sentence);
    cout << sentence << endl;
    vector<string> afterSplit;
    afterSplit = split(sentence);
    vector<string>::const_iterator constIter = afterSplit.begin();
    cout << "Here is the result" << endl;
    while(constIter != afterSplit.end())
    {
        cout << *constIter << endl;
        ++constIter;
    }
}
