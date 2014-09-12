#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //max

#include "Declaration.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void framingAName()
{
    cout<<"Input a Name: "<<endl;
    std::string name;
    cin>>name;
    std::string frame = "Hello, " + name +"!";
/*

  *************
  *           *
  * Hello,Bo! *
  *           *
  *************

  */
    for (int i = 0; i < 5; i++)
    {
        for(std::string::size_type c = 0; c < frame.length()+4; c++)
        {
            if(i == 0 || i == 4 || c == 0 || c == frame.length()+3)
            {
                cout << "*";
            } else if (i == 1 || i == 3 || (i == 2 && ((c == 1) || (c == frame.length()+2))))
            {
                cout << " ";
            } else /*if (i == 2 && c == 2)*/{
                cout << frame;
                c += frame.length() - 1;
            }
        }
        cout << endl;
    }
}

void framingAVector()
{
    vector<string> sentence;
    sentence.push_back("Welcome");
    sentence.push_back("to");
    sentence.push_back("my");
    sentence.push_back("world!");

    vector<string> frame;
    frame = framingAVector(sentence);
    for(vector<string>::const_iterator iter = frame.begin();
        iter != frame.end();
        ++iter)
    {
        cout << *iter << endl;
    }

    cout << endl << endl << "Virtical Connect:" << endl;
    vector<string> virticalConnetion = virticalConnect(sentence, frame);
    for(vector<string>::const_iterator iter = virticalConnetion.begin();
        iter != virticalConnetion.end();
        ++iter)
    {
        cout << *iter << endl;
    }
}

vector<string> framingAVector(const vector<string>& sentence)
{    
    string::size_type width = 0;
    for(vector<string>::size_type i = 0; i < sentence.size(); ++i)
    {
        width = std::max(width, sentence[i].size());
    }

    vector<string> ret;

    string border(width+4, '*');
    ret.push_back(border);
    string currentRow;
    for(vector<string>::size_type i = 0; i < sentence.size(); ++i)
    {
        //Note:
        //here you CANNOT use '*' + sentence[i], it has to be "* " + sentence[i]
        currentRow = "* " + sentence[i] +
                std::string(width + 1 - sentence[i].size(), ' ') + "*";
        ret.push_back(currentRow);
    }
    ret.push_back(border);
    return ret;
}

std::vector<std::string> virticalConnect(const std::vector<std::string> &top,
                                         const std::vector<std::string> &bottom)
{
    vector<string> ret;
    ret.insert(ret.begin(), top.begin(), top.end());
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}
