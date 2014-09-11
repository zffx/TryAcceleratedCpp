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

vector<string> framingAVector(const vector<string>& sentence)
{
    string::size_type width = 0;
    for(vector<string>::size_type i = 0; i < sentence.size(); ++i)
    {
        width = std::max(width, sentence[i].size());
    }
}
