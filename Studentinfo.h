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
    const std::vector<double>& homeworkGradesConst() const;
    std::vector<double>& homeworkGrades();

private:
    std::string mName;
    double mMidterm;
    double mFinal;
    std::vector<double> mHomeworkGrades;
};

/*Methods that doesn't impact the value of the attributes in a class should not
be a method inside the class*/
    bool compare(const StudentInfo& student1, const StudentInfo& student2);
    bool didAllHomework(const StudentInfo& studentInfo);

#endif // STUDENTINFO_H
