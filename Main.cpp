#include <iostream>
#include "Declaration.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Input the number to run:" <<endl
         << "1. Framing a name" << endl
         << "2. Calculate final grade with Avg homework grade" << endl
         << "3. Calculate final grade with Med homework grade" << endl;

    unsigned int choice = 0;
    cin >> choice ;

    switch(choice)
    {
    case 1:
        framingAName();
        break;
    case 2:
        avg();
        break;
    case 3:
        med();
        break;
    default:
        break;
    }
}
