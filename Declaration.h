#ifndef DECLARATION_H
#define DECLARATION_H

#include <vector>
#include <istream>

void framingAName();
void avg();

std::istream& readHomeworkGrades(
		std::istream& in,
		std::vector<double>& homeworkGrades);

double median(std::vector<double> homeworkGrades);

double grade(double midterm, double final, double homework);
double grade(
		double midterm,
		double final,
		const std::vector<double>& homeworkGrades);

void med();

#endif // DECLARATION_H
