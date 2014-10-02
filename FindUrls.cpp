#include "Declaration.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm> //std::search

/*
URL example:
protocol-name://resource-name
*/

bool notUrlChar(char c)
{
    static const std::string validUrlChars = "~;/?:@=&$-_.+!*'()"; //static const!
    return (
                /*
                  c is not a letter or a number,
                  and c is not one of the valideUrlChars above
                */
                find(validUrlChars.begin(), validUrlChars.end(),c) == validUrlChars.end() &&
                !isalnum(c)
                );
}

std::vector<std::string> findUrls(const std::string &s)
{
    std::vector<std::string> ret;
    typedef std::string::const_iterator iter;
    iter iterI = s.begin();

    std::string separator = "://";

    while((iterI = std::search(iterI,
                               s.end(),
                               separator.begin(),
                               separator.end())) != s.end()) //std::search!
    {
        if(iterI != s.begin() && iterI +separator.length() != s.end())
        {
            iter iterB = iterI;
            while(isalpha(*(iterB - 1)) && iterB != s.begin())
            // *(iterB -1) equals to iterB[-1]
            {
                --iterB;
            }

            iter iterE = std::find_if(iterI, s.end(),notUrlChar);

            if((iterB != iterI) && !notUrlChar(iterI[separator.size()]))
            {
                ret.push_back(std::string(iterB, iterE)); //string(iter1, iter2)
            }
        }
        iterI = iterI + separator.size();
    }
    return ret;
}

void parseURLs()
{
    std::string s = "://  http://abc.com    I think of you, always"
                  " https://helloworld.org    ://a  b://  ://";
    std::cout << "Input: \n" << s << std::endl;
    std::vector<std::string> URLs;
    URLs = findUrls(s);
    std::cout << "Output: " << std::endl;
    for(std::vector<std::string>::size_type i = 0; i < URLs.size(); ++i)
    {
        std::cout << URLs.at(i) << std::endl;
    }
}
