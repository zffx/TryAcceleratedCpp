#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::setprecision;
using std::vector;

void med()
{
    cout << "Enter your first name: " << endl;
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, followed by end-of-file";

    vector<double> homeworkGrades;

    double current = 0;

    while(cin >> current)
    {
        homeworkGrades.push_back(current);
    }

    if (homeworkGrades.size() == 0)
    {
        cout << endl << "You must enter your grades. Try again." << endl;
        return;
    }

    std::sort(homeworkGrades.begin(),homeworkGrades.end());

    double medGrade = homeworkGrades.size() % 2 == 0 ?
                (homeworkGrades.at(homeworkGrades.size()/2) +
                    homeworkGrades.at(homeworkGrades.size()/2-1))/2 :
                homeworkGrades.at(homeworkGrades.size()/2);

    streamsize defaultPrec = cout.precision();
    double overallGrade = midterm * 0.2 + final * 0.4 + medGrade * 0.4;
    cout << "Your overall grade is " << setprecision(3) << overallGrade <<
         setprecision(defaultPrec) << endl;    
}
