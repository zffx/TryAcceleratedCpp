#include <iostream>
#include "Declaration.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Input the number to run:" <<endl
         << "1. Framing a name" << endl
         << "2. Calculate Avg Grade" << endl;
    unsigned int choice = 0;
    cin >> choice ;
    switch(choice)
    {
    case 1:
        framingAName();
        break;
    case 2:
        avg();
    default:
        break;
    }
}
