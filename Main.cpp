#include "Declaration.h"

#include <string>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Input the number to run:" <<endl
         << "1. Framing a name" << endl
         << "2. Calculate final grade with Avg homework grade" << endl
         << "3. Calculate final grade with Med homework grade" << endl
         << "4. Split a sentence with \' \'" << endl
         << "5. Framing a sentence" << endl
         << "6. Finding URLs from a string" << endl
         << "7. Analyse students' grades" << endl
         << "8. Number of same words in a sentence" << endl;
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
    case 4:
        splitAString();
        break;
    case 5:
        framingAVector();
        break;
    case 6:
        parseURLs();
        break;
    case 7:
        analyseGrades();
        break;
    case 8:
        sameWordStatistic("./data/text_input");
        break;
    default:
        break;
    }
}
