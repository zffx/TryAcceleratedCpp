#include <iomanip>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //std::sort
#include <stdexcept> //std::domain_error

#include "Declaration.h"
#include "Studentinfo.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::setprecision;
using std::vector;

namespace Utils
{
typedef vector<double>::size_type vecDoublesz;

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
        throw std::domain_error("Student hasn't done any homework!");
    }

    return grade(midterm, final, median(homeworkGrades));
}

bool gradeFail(const StudentInfo& studentInfo)
{
    return studentInfo.grade() >= 60 ? true : false;
}

void med()
{
    vector<StudentInfo> studentList;
    StudentInfo student;
    string::size_type maxLength = 0;
    while (student.readStudentInfo(cin))
    {
        maxLength = std::max(maxLength, student.name().size());
        studentList.push_back(student);
    }

    std::sort(studentList.begin(), studentList.end(), compare);
    for(vector<StudentInfo>::size_type i = 0; i < studentList.size(); i++)
    {
        try
        {
            streamsize defaultPrec = cout.precision();
            cout << studentList.at(i).name()<<"\'s"
                 << string(maxLength - studentList.at(i).name().size()+1, ' ')
                 <<" overall grade is "
                 << setprecision(3) << studentList.at(i).grade()
                 << setprecision(defaultPrec) << endl;
        }
        catch (std::domain_error e)
        {
            cout << e.what(); //what() can get a copy of the error message.
            return;
        }
    }
}
}
