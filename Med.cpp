#include <iomanip>

#include <string>
#include <vector>
#include <fstream>
#include <algorithm> //std::sort
#include <stdexcept> //std::domain_error

#include "Declaration.h"
#include "Studentinfo.h"
#include "Utils.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::setprecision;
using std::vector;


using namespace Utils;
void med()
{
    vector<StudentInfo> studentList;
    StudentInfo student;
    string::size_type maxLength = 0;

    std::ifstream infile("./data/grades");
    while (student.readStudentInfo(infile))
    {
        maxLength = std::max(maxLength, student.name().size());
        studentList.push_back(student);
    }

    //below are different ways of extract fails
    //studentList = extractFails(studentList);//uncomment to exam extractFails()
    //studentList = extractFailsByIter(studentList);
    //studentList = extractFailsByRmCp(studentList);
    studentList = extractFailsByPartition(studentList);

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
                In order to execute correctly, this expression requires
                parentheses that override the normal operator precedence.
                The exporession *iter returns the value that the iterator
                iter denotes. The precedence of . is higher than the precedence
                of *, wich means  that if we want the * operations to apply
                only to the left operand of the ., we must enclose *iter in
                parentheses to get (*iter). If we wrote *iter.name, the complier
                would treat it as *(iter.name).
                */
                 <<" overall grade is "
                << setprecision(3) << (*iter).grade()
                << setprecision(defaultPrec) << endl;
        }
        catch (std::domain_error &e)
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
        catch (std::domain_error &e)
        {
            cout << e.what(); //what() can get a copy of the error message.
            return;
        }
    }
}


