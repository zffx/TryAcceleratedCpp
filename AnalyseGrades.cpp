#include "Declaration.h"
#include "Studentinfo.h"

#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>

using std::vector;

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
}
