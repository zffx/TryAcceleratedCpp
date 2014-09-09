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
    return studentInfo.grade() < 60 ? true : false;
}

vector<StudentInfo> extractFails(vector<StudentInfo>& students)
{
    vector<StudentInfo> fails;
    vector<StudentInfo>::size_type i = 0;
    while(i < students.size()) //students.size() can change in the loop!
    {
        if(gradeFail(students.at(i)))
        {
            fails.push_back(students.at(i));
            students.erase(students.begin()+i); //you can only erase an element
            //by an iterator! students.begin()+i
        }
        else
            ++i;
    }
    return fails;
}

vector<StudentInfo> extractFailsByIter(vector<StudentInfo>& students)
{
    vector<StudentInfo> fails;
    vector<StudentInfo>::iterator iter = students.begin();
    while(iter != students.end())//you have to keep students.end() here for each
    //round of the loop, instead of take the value first(e.g. assign it to end_iter)
    //and use it here, since erase() invalidates the end_iter.
    {
        if(gradeFail(*iter))
        {
            fails.push_back(*iter);
            iter = students.erase(iter); /* You have to assign the return value
            back to iter again! Since vector.erase(iter) invalidates the iter
            and all iterators that refer to elements after the one that was just
            erased. erase() returns an iterator that is poistioned on the element
            that follows the one that we just erased.*/
        }
        else
            ++iter;
    }
    return fails;
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

    //studentList = extractFails(studentList); //uncomment to exam extractFails()
    studentList = extractFailsByIter(studentList);
    std::sort(studentList.begin(), studentList.end(), compare);

    //iterator version
    for(vector<StudentInfo>::const_iterator iter = studentList.begin();
        iter != studentList.end();
        ++iter)
    {
        try
        {
            streamsize defaultPrec = cout.precision();
            cout << iter->name()<<"\'s"
                 << string(maxLength - (*iter).name().size()+1, ' ')
        /*
        In order to execute correctly, this expression requires parentheses that
        override the normal operator precedence. The exporession *iter returns
        the value that the iterator iter denotes. The precedence of . is higher
        than the precedence of *, wich means  that if we want the * operations
        to apply only to the left operand of the ., we must enclose *iter in
        parentheses to get (*iter). If we wrote *iter.name, the complier would
        treat it as *(iter.name).
        */
                 <<" overall grade is "
                 << setprecision(3) << (*iter).grade()
                 << setprecision(defaultPrec) << endl;
        }
        catch (std::domain_error e)
        {
            cout << e.what(); //what() can get a copy of the error message.
        }
    }
    cout << endl << endl;

    //index version
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
