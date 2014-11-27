#include "Declaration.h"
#include "Studentinfo.h"

#include <iostream>
#include <vector>
#include <stdexcept> //std::domain_error
#include <numeric> //std::accumulate
#include <algorithm> /*std::sort, std::remove_copy, std::remove_copy_if,
                       std::remove_if, std::parttition*/
/*
Algorithms act on container elements¡ªthey do not act on containers.
The sort, remove_if, and partition functions all move elements to new positions
in the underlying container, but they do not change the properties of the
container itself. For example, remove_if does not change the size of the
container on which it operates; it merely copies elements around within the
container.When we need to shorten the vector to discard the "invalid" elements,
we must do so ourselves with erase. Note that erase must be a member of vector
because it acts directly on the container, not just on its elements.
*/

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
    /*
    std::remove_copy
    exclude all the elements with value 0.0 and copy all the
    other elements to turnedInHomework
    */
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
    /*
    remove_copy_if()
    exclude all elements fufil gradePass and copy all the other elements
    (students with failed grade) to failed vector
    */
    std::remove_copy_if(students.begin(),
                        students.end(),
                        std::back_inserter(failed),
                        gradePass);

    /*remove_if() does not really delete/erease the elements fufilling the
    condition, it reorders the vector, put all elements which doesn't fufil the
    condition in the front, and it returns the iterator pointing to the end of
    the "good" elements*/

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
    /*
    Both remove_if and partition put the "good" elements first. partition puts
    the "bad" elements after that, whereas remove_if does not specify what comes
    after it -- it might be the bad elements, but it might also be copies of
    any (either good or bad) elements.

    For example, if you partition 1 2 3 4 5 on even, you might get 2 4 5 3 1
    (note that each element occurs exactly once), whereas if you remove_if the
    odd elements, you might get 2 4 3 4 5 (note the duplicates).*/
}


}//end of namespace Utils

