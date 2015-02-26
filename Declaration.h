#ifndef DECLARATION_H
#define DECLARATION_H

#include <string>
#include <vector>
#include <iostream>
#include "Studentinfo.h"

void framingAName();
void avg();
void med();

//start of grade analysis
double medianAnalysis(const std::vector<StudentInfo>&);
double averageAnalysis(const std::vector<StudentInfo>&);
double optMedianAnalysis(const std::vector<StudentInfo>&);

void writeAnalysis(std::ostream& out,
                   const std::string& name,
                   double analysisFunction(const std::vector<StudentInfo>&),
                   const std::vector<StudentInfo>& did,
                   const std::vector<StudentInfo>& didnt);

void analyseGrades();
//end of grade analysis

//start of string operation
void splitAString();
std::vector<std::string> split(const std::string &sentence);

bool space(char c);
bool notSpace(char c);
std::vector<std::string> splitAdvanced(const std::string &sentence);

bool isPalindrome(const std::string& s);
//end of string operation


//start of framing
void framingAVector();

std::vector<std::string>
framingAVector(const std::vector<std::string> &sentence);

std::string::size_type width(const std::vector<std::string> &sentence);

std::vector<std::string>
verticalConcatenate(const std::vector<std::string> &top,
                    const std::vector<std::string> &bottom);

std::vector<std::string>
horizontalConcatenate(const std::vector<std::string> &left,
                      const std::vector<std::string> &right);
//end of framing

//start of URL process
void parseURLs();
bool notUrlChar(char c);
std::vector<std::string> findUrls(const std::string &s);
//end of URL process

//start of same words statistics
void removePunctuation(std::string& word);
void sameWordStatistic(const std::string& txtFilePath);
//start of same words statistics

//start of generate sentence
void generateSentence(const std::string &txtFilePath);
//end of generate sentence
#endif // DECLARATION_H
