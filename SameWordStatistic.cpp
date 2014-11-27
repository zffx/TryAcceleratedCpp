#include "Declaration.h"

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm> //std::find

void removePunctuation(std::string& word)
{
    static const std::string punctuation = ",.!?;:";

    if(std::find(punctuation.begin(),
                 punctuation.end(),
                 word[word.size()-1])!= punctuation.end())
    {
        std::cout << "remove punction from: " << word << "\t\t";
        word.erase(word.end()-1);
        std::cout << "after removal: " << word << std::endl;
    }
}

void sameWordStatistic(const std::string &txtFilePath)
{

    std::cout << "Parsing words from: " << txtFilePath << std::endl;
    std::map<std::string, int> counter;
    /*
    note here you cannot use
    std::ifstream infile(txtFilePath);
    ifstream does not accept std::sting, see the right way below:
    */
    std::ifstream infile(txtFilePath.c_str());
    std::string word;
    while(infile >> word)
    {
        removePunctuation(word);
        counter[word]++;
    }

    //how to iterate through a map:
    for(std::map<std::string, int>::const_iterator iter = counter.begin();
        iter != counter.end();
        iter++)
    {
        std::cout << iter->first << ": " << iter->second << std::endl;
    }
}


