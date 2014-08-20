#include "Studentinfo.h"
#include "Declaration.h"

#include <iostream>

using std::cout;
using std::endl;

StudentInfo::StudentInfo()
{
    cout << "StudentInfo::StudentInfo()" << endl;
}

StudentInfo::StudentInfo(std::istream& in)
{
    cout << "StudentInfo::StudentInfo(std::istream& in)" << endl;
    in >> mName >> mMidterm >> mFinal;
    readHomeworkGrades(in);
}

std::istream& StudentInfo::readHomeworkGrades(std::istream& in)
{
    if(in)
    {
        mHomeworkGrades.clear();
        double current = 0;
        while(in >> current)
        {
            mHomeworkGrades.push_back(current);
        }
        in.clear();
    }
    return in;
}

double StudentInfo::grade() const
{
    return Utils::grade(mMidterm, mFinal, mHomeworkGrades);
}
