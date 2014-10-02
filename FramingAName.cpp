#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //max, copy

#include "Declaration.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void framingAName()
{
    cout<<"Input a Name: "<<endl;
    string name;
    cin>>name;
    string frame = "Hello, " + name +"!";
    /*

  *************
  *           *
  * Hello,Bo! *
  *           *
  *************

  */
    for (int i = 0; i < 5; i++)
    {
        for(string::size_type c = 0; c < frame.length()+4; c++)
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

    cout << endl << endl << "Vertical Concatenate:" << endl;
    vector<string> verticalConnetion = verticalConcatenate(sentence, frame);
    for(vector<string>::const_iterator iter = verticalConnetion.begin();
        iter != verticalConnetion.end();
        ++iter)
    {
        cout << *iter << endl;
    }

    cout << endl << endl << "Horizontal Concatenate:" << endl;
    vector<string> horizontalConnetion = horizontalConcatenate(sentence, frame);
    for(vector<string>::const_iterator iter = horizontalConnetion.begin();
        iter != horizontalConnetion.end();
        ++iter)
    {
        cout << *iter << endl;
    }

}

vector<string> framingAVector(const vector<string>& sentence)
{    
    string::size_type w = width(sentence);

    vector<string> ret;

    string border(w+4, '*');
    ret.push_back(border);
    string currentRow;
    for(vector<string>::size_type i = 0; i < sentence.size(); ++i)
    {
        //Note:
        //here you CANNOT use '*' + sentence[i], it has to be "* " + sentence[i]
        //char cannot be implicitly converted to string for "+" operation!
        currentRow = "* " + sentence[i] +
                string(w + 1 - sentence[i].size(), ' ') + "*";
        ret.push_back(currentRow);
    }
    ret.push_back(border);
    return ret;
}

vector<string> verticalConcatenate(const vector<string> &top,
                                   const vector<string> &bottom)
{
    vector<string> ret;
    //This is the right way to concatenate to vector!
    //vector.insert()
    ret.insert(ret.begin(), top.begin(), top.end());

    //This is a even better way to concatenate vector!
    //std::copy()
    std::copy(bottom.begin(), bottom.end(), std::back_inserter(ret));
    return ret;
}


/*
this is an  **************
example     * this is an *
to          * example    *
illustrate  * to         *
framing     * illustrate *
            * framing    *
            **************
*/

vector<string> horizontalConcatenate(const vector<string> &left,
                                     const vector<string> &right)
{
    vector<string> ret;
    string::size_type w = width(left) + 1;
    vector<string>::size_type i = 0, j = 0;

    while (i != left.size() || j != right.size())
    {
        string cursor;
        if(i != left.size())
        {
            cursor = left[i];
            ++i;
        }

        //you cannot use w - left[i].size() here! IndexOutOfBounds for last i!
        //you can use += to concatenate two strings.
        cursor += string(w - cursor.size(), ' ');

        if(j != right.size())
        {
            cursor += right[j];
            ++j;
        }
        ret.push_back(cursor);
    }
    return ret;
}


string::size_type width(const vector<string> &sentence)
{
    string::size_type width = 0;
    for(vector<string>::size_type i = 0; i < sentence.size(); ++i)
    {
        width = std::max(width, sentence[i].size());
    }
    return width;
}
