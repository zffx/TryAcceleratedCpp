#include "Declaration.h"
#include "Studentinfo.h"
#include "Utils.h"

#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <algorithm> //std::transform

using std::vector;
using std::string;
using std::endl;
using std::cout;


/*this function is going to return the median value of all grades of
student's homework calculated by median grade of homework*/
double medianAnalysis(const vector<StudentInfo>& students)
{
    vector<double> grades;
    //std::transform!
    std::transform(students.begin(),
                   students.end(),
                   std::back_inserter(grades), //back_inserter()!!
                   //have to be a static function here which returns double
                   Utils::gradeMedian);
    return Utils::median(grades);
}

/*this function is going to return the median value of all grades of
student's homework calculated by average grade of homework*/
double averageAnalysis(const vector<StudentInfo>& students)
{
    vector<double> grades;
    std::transform(students.begin(),
                   students.end(),
                   std::back_inserter(grades),
                   Utils::gradeAverage);
    return Utils::median(grades);
}

/*this function is going to return the median value of all grades of
student's homework calculated by median grade of only turned-in homework*/
double optMedianAnalysis(const vector<StudentInfo>& students)
{
    vector<double> grades;
    //std::transform!
    std::transform(students.begin(),
                   students.end(),
                   std::back_inserter(grades), //back_inserter()!!
                   //have to be a static function here which returns double
                   Utils::gradeOptMedian);
    return Utils::median(grades);
}

void writeAnalysis(std::ostream& out,
                   const string& name,
                   //declare a parameter to represent a function
                   double analysisFunction(const vector<StudentInfo>&),
                   const vector<StudentInfo>& did,
                   const vector<StudentInfo>& didnt)
{
    out << name << ": " << "median(did) = " << analysisFunction(did) <<
           ", median(didnt) = " << analysisFunction(didnt) << endl;
}

void analyseGrades()
{
    std::ifstream infile("./data/grades");

    vector<StudentInfo> did, didnt;
    StudentInfo student;
    while(student.readStudentInfo(infile))
    {
        if(didAllHomework(student))
        {
            did.push_back(student);
        }
        else
        {
            didnt.push_back(student);
        }
    }
    cout << "nubmer of students did all homework: " << did.size() << endl;
    cout << "nubmer of students didn't do' all homework: "
         << didnt.size() << endl;

    writeAnalysis(cout, "median", medianAnalysis, did, didnt);
    writeAnalysis(cout, "average", averageAnalysis, did, didnt);
    writeAnalysis(cout, "optimistic median", optMedianAnalysis, did, didnt);
}
