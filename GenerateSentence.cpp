#include "Declaration.h"

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdexcept> //std::domain_error

using std::map;
using std::vector;
using std::string;

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef map<string, RuleCollection> Grammar;

Grammar readGrammar(std::istream& input)
{
    Grammar ret;
    string line;
    vector<string> keyAndRule;
    while(std::getline(input, line))
    {
        std::cout << line << std::endl;
        keyAndRule = split(line);
        if(!keyAndRule.empty())
        {
            ret[keyAndRule[0]].push_back(
                        Rule(keyAndRule.begin()+1, keyAndRule.end()));
        }
    }
    return ret;
}

bool isExpandable(const std::string& element)
{
    return !element.empty() &&
           element[0] == '<' &&
           element[element.length()-1] == '>';
}

string expand(const std::string& element ,const Grammar& grammar)
{
    std::cout << element << std::endl;
    string ret;
    if(isExpandable(element))
    {
        vector<Rule> ruleList;
        ruleList = grammar.at(element);

        vector<string>::const_iterator iter = ruleList[0].begin();
        for(;iter != ruleList[0].end(); ++iter)
        {
            try{
                ret = expand(*iter, grammar);
            }
            catch (...)
            {
                abort();
            }
        }
    }
    else
    {
        return ret += element + " ";
    }
}

void generateSentence(const std::string& txtFilePath)
{
    std::fstream infile(txtFilePath.c_str());
    Grammar grammar = readGrammar(infile);
    string sentence = expand("<sentence>", grammar);
    std::cout << "\n\ngenerateSentence()" << std::endl;
    std::cout << sentence << std::endl;
}
