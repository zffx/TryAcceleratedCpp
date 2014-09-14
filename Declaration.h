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

bool space(char c);
bool notSpace(char c);
std::vector<std::string> splitAdvanced(const std::string &sentence);


void framingAVector();

std::vector<std::string> framingAVector(const std::vector<std::string> &sentence);

std::string::size_type width(const std::vector<std::string> &sentence);

std::vector<std::string> verticalConcatenate(const std::vector<std::string> &top,
                                         const std::vector<std::string> &bottom);

std::vector<std::string> horizontalConcatenate(const std::vector<std::string> &left,
										   const std::vector<std::string> &right);
#endif // DECLARATION_H
