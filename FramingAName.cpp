#include <iostream>
#include <string>

#include "Declaration.h"

void framingAName()
{
    using std::cin;
    using std::cout;
    using std::endl;

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
