#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <string>
#include <vector>
#include <iostream>

class StudentInfo
{
public:
    StudentInfo();
    StudentInfo(std::istream& in);

    std::istream& readStudentInfo(std::istream& in);
    std::istream& readHomeworkGrades(std::istream& in);
    double grade() const;

    std::string name() const;

private:
    std::string mName;
    double mMidterm;
    double mFinal;
    std::vector<double> mHomeworkGrades;
};

    bool compare(const StudentInfo& student1, const StudentInfo& student2);
#endif // STUDENTINFO_H
