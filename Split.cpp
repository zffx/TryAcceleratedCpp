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
            ret.push_back(sentence.substr(i,j - i)); //string.substr(i,j)!!
            i = j;
        }
    }
    return ret;
}

/*
    You HAVE TO provide your own space/notSpace method since
    isspace() in <cctype> is overloaded and find_if will not
    know which version of isspace() to call if you put it
    directly there like: find_if(i, sentence.end(), isspace);
    --Accelerated Cpp
*/
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
        /*seems I can use isspace directly here...
          book might be old?*/
        j = find_if(i, sentence.end(), isspace);

        // if we found some nonwhitespace characters
        if(i != sentence.end())
        {
            ret.push_back(string(i,j));
            i = j;
        }
    }
    return ret;
}

bool isPalindrome(const string& s)
{
    return std::equal(s.begin(), s.end(), s.rbegin());
}

void splitAString()
{
    cout << "The sentence is: Welcome to my world!" << endl;
    string sentence = "  Welcome to my world! ";
    vector<string> afterSplit;
    afterSplit = split(sentence);
    vector<string>::const_iterator constIter = afterSplit.begin();
    cout << "Here is the result after split with index of std::string:" << endl;
    while(constIter != afterSplit.end())
    {
        cout << *constIter << endl;
        ++constIter;
    }

    afterSplit = splitAdvanced(sentence);
    cout << endl;
    cout << "Here is the result after splitAdvanced with stl::algorithm:"
         << endl;

    constIter = afterSplit.begin();
    while(constIter != afterSplit.end())
    {
        cout << *constIter << endl;
        ++constIter;
    }
    cout << endl << "sentence is " << sentence << endl;
    cout << "isPalindrome: ";
    string palindrome = isPalindrome(sentence)? "true" : "false";
    cout << palindrome << endl;

    sentence = "YannaY";
    cout << "sentence changed to YannaY" << endl;
    cout << "isPalindrome: ";
    palindrome = isPalindrome(sentence)? "true" : "false";
    cout << palindrome << endl;

}
