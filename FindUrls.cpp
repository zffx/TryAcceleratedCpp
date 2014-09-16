#include "Declaration.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

//URL:
// protocol-name://resource-name

bool notUrlChar(char c)
{
    static const std::string validUrlChars = "~;/?:@=&$-_.+!8'()";
    return (find(validUrlChars.begin(), validUrlChars.end(),c)
                                        == validUrlChars.end()&&
            !isalnum(c));
}

std::vector<std::string> findUrls(const std::string &s)
{
    std::vector<std::string> ret;
    std::string::const_iterator iterI = s.begin();
    std::string::const_iterator iterJ = s.begin();
    std::string::const_iterator iterB = s.begin();
    std::string::const_iterator iterE = s.begin();
    std::string separator = "://";

    while((iterI = std::search(iterI,
                               s.end(),
                               separator.begin(),
                               separator.end())) != s.end())
    {
        if(iterI == s.begin())
        {
            iterI = iterI + separator.size();
            continue;
        }
        if(iterJ == iterI + separator.size())
        {
            break;
        }
        iterJ = iterI + separator.size();

        iterE = iterB = iterI;
        while(isalpha(*(iterB -1)) && iterB != s.begin())
        {
            --iterB;
        }
        //std::cout << "*iterB " << *iterB << std::endl;
        iterE = std::find_if(iterJ, s.end(),notUrlChar);
        //std::cout << "*iterE " << *iterE << std::endl;
        if((iterB != iterI) && !notUrlChar(*(iterI+separator.size())))
        {
            ret.push_back(std::string(iterB, iterE));
        }
        iterI = iterJ;
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
