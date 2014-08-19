#include <iomanip>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept> //std::domain_error

#include "Declaration.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::setprecision;
using std::vector;

typedef vector<double>::size_type vecDoublesz;

std::istream& readHomeworkGrades(std::istream& in,
								 std::vector<double>& homeworkGrades)
{

}

double median(std::vector<double> homeworkGrades)
{
	vecDoublesz size = homeworkGrades.size();
    if ( size == 0)
    {
        cout << endl << "You must enter your grades. Try again." << endl;
        throw std::domain_error("Homework Grades cannot be empty!");
    }

    std::sort(homeworkGrades.begin(),homeworkGrades.end());


    double medGrade = size % 2 == 0 ?
                (homeworkGrades.at(size/2) + homeworkGrades[size/2-1]) / 2 :
                homeworkGrades.at(size/2);
    //.at() has boundary check but [] doesn't
    return medGrade;
}

double grade(double midterm, double final, double homework)
{
	return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

double grade(double midterm,
			 double final,
			 const std::vector<double>& homeworkGrades)
{
    if (homeworkGrades.size() == 0)
    {
        throw std::domain_error("Homework Grades cannot be empty!");
    }

	return grade(midterm, final, median(homeworkGrades));
}

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

    streamsize defaultPrec = cout.precision();
    cout << "Your overall grade is " << setprecision(3) <<
    		grade(midterm, final, homeworkGrades) <<
    		setprecision(defaultPrec) << endl;
}
