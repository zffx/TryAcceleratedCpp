#include <iomanip> //to use std::setprecision
#include <iostream>
#include <string>

#include "Declaration.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::setprecision;

void avg()
{
    cout << "Enter your first name: " << endl;
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, followed by end-of-file";

    int count = 0;
    double sum = 0;
    double current = 0;

    while(cin >> current)
    {
        sum += current;
        ++count;
    }

    //Use cout.precision to set the precision of output
    //streamsize type
    streamsize defaultPrec = cout.precision();
    double overallGrade = midterm * 0.2 + final * 0.4 + sum / count * 0.4;
    cout << "Your overall grade is " << setprecision(3) << overallGrade <<
         setprecision(defaultPrec) << endl;
}
