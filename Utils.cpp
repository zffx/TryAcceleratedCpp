#include "Declaration.h"
#include "Studentinfo.h"

#include <iostream>
#include <vector>
#include <algorithm> /*std::sort, std::remove_copy, std::remove_copy_if,
                       std::remove_if, std::parttition*/
#include <numeric> //std::accumulate
#include <stdexcept> //std::domain_error

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
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

double average(std::vector<double> homeworkGrades)
{
    vecDoublesz size = homeworkGrades.size();
    if (size == 0) return 0.0;
    return std::accumulate(homeworkGrades.begin(),
                           homeworkGrades.end(),
                           0.0) / homeworkGrades.size();
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

double gradeMedian(const StudentInfo &studentInfo)
{
    return studentInfo.grade();
}

double gradeAverage(const StudentInfo &studentInfo)
{
    return grade(studentInfo.midterm(),
                 studentInfo.final(),
                 average(studentInfo.homeworkGradesConst()));
}

double gradeOptMedian(const StudentInfo &studentInfo)
{
    vector<double> turnedInHomework;
    //std::remove_copy
    std::remove_copy(studentInfo.homeworkGradesConst().begin(),
                     studentInfo.homeworkGradesConst().end(),
                     std::back_inserter(turnedInHomework),
                     0.0);

    if(turnedInHomework.empty())
    {
        return grade(studentInfo.midterm(),
                     studentInfo.final(),
                     0);
    }
    else
    {
        return grade(studentInfo.midterm(),
                     studentInfo.final(),
                     median(turnedInHomework));
    }
}

bool gradeFail(const StudentInfo& studentInfo)
{
    return studentInfo.grade() < 60 ? true : false;
}

bool gradePass(const StudentInfo &studentInfo)
{
    return !gradeFail(studentInfo);
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
        //round of the loop, instead of take the value first(e.g. assign it to
        //end_iter) and use it here, since erase() invalidates the end_iter.
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

vector<StudentInfo> extractFailsByRmCp(vector<StudentInfo> &students)
{
    vector<StudentInfo> failed;
    //remove_copy_if(), move all failed students to failed vector
    std::remove_copy_if(students.begin(),
                        students.end(),
                        std::back_inserter(failed),
                        gradePass);

    /*remove_if() does not really delete/erease the elements fufil the
    condition, it reorders the vector, put all elements which doesn't fufil the
    condition in the front and the ones which fufil the condition in the end,
    and it returns the iterator pointing to the first element that fulfil the
    condition*/

    /*then use vector.erase() to delete the failed elements in the end of the
      vector*/
    students.erase(std::remove_if(students.begin(),students.end(),gradeFail),
                   students.end());
    return failed;
}

vector<StudentInfo> extractFailsByPartition(vector<StudentInfo> &students)
{
    //std::stable_partition()
    vector<StudentInfo>::iterator iter =
            std::stable_partition(students.begin(),
                                  students.end(),
                                  gradePass);
    vector<StudentInfo> failed(iter, students.end());
    students.erase(iter,students.end());
    return failed;
}


}//end of namespace Utils

