#ifndef DECLARATION_H
#define DECLARATION_H

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
        const std::vector<double>& homeworkGrades);

void med();

bool gradeFail(const StudentInfo& studentInfo);

std::vector<StudentInfo> extractFails(std::vector<StudentInfo>& students);

}
#endif // DECLARATION_H
