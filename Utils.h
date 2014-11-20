#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

#include "Studentinfo.h"

namespace Utils
{

double median(std::vector<double> homeworkGrades);
double average(std::vector<double> homeworkGrades);

double grade(double midterm, double final, double homework);
double grade(
        double midterm,
        double final,
        const std::vector<double> &homeworkGrades);

double gradeMedian(const StudentInfo&);
double gradeAverage(const StudentInfo&);
double gradeOptMedian(const StudentInfo&);

bool gradeFail(const StudentInfo &studentInfo);
bool gradePass(const StudentInfo &studentInfo);

std::vector<StudentInfo> extractFails(std::vector<StudentInfo> &students);
std::vector<StudentInfo> extractFailsByIter(std::vector<StudentInfo> &students);
std::vector<StudentInfo> extractFailsByRmCp(std::vector<StudentInfo> &students);
std::vector<StudentInfo> extractFailsByPartition(std::vector<StudentInfo> &students);

}

#endif // UTILS_H
