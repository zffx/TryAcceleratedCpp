#ifndef DECLARATION_H
#define DECLARATION_H

#include <string>
#include <vector>
#include <istream>
#include "Studentinfo.h"

void framingAName();

namespace Utils
{
void avg();

double median(std::vector<double> homeworkGrades);

double grade(double midterm, double final, double homework);
double grade(
        double midterm,
        double final,
        const std::vector<double> &homeworkGrades);

void med();

bool gradeFail(const StudentInfo &studentInfo);

std::vector<StudentInfo> extractFails(std::vector<StudentInfo> &students);

std::vector<StudentInfo> extractFailsByIter(std::vector<StudentInfo> &students);

}

void splitAString();
std::vector<std::string> split(const std::string &sentence);

void framingAVector();
std::vector<std::string> framingAVector(const std::vector<std::string> &sentence);

std::vector<std::string> virticalConnect(const std::vector<std::string> &top,
                                         const std::vector<std::string> &bottom);

#endif // DECLARATION_H
