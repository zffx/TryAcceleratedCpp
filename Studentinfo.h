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

    std::istream& readHomeworkGrades(std::istream& in);
    double grade() const;

    std::string Name() const;
    void setName(const std::string& name);
    double Midterm() const;
    void setMidterm(double midterm);
    double Final() const;
    void setFinal(double final);
    std::vector<double> HomeworkGrades() const;
    const std::vector<double> &HomeworkGradesConst() const;

private:
    std::string mName;
    double mMidterm;
    double mFinal;
    std::vector<double> mHomeworkGrades;
};

#endif // STUDENTINFO_H
