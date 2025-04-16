#ifndef MODULESKONDRATENKO_H_INCLUDED
#define MODULESKONDRATENKO_H_INCLUDED

#include <cmath>
#include <string>
using namespace std;

double s_calculation(double x, double y, double z);
double salary_calculation(double salary, int experience, double office_salary);
void temperature_calculation(const double temps[], int size, double& avg_celsius, double& avg_fahrenheit);
double analyze_bit(unsigned int N);
string getAuthorInfo();
string extractUppercase(const string& filename);
string checkPunctuation(const string& filename);
void writePoemVertically(const string& inputFile, const string& outputFile);
string getFileSizeKB(const string& filename);
string getCurrentDateTime();
string toBinary(int b);

#endif // MODULESKONDRATENKO_H_INCLUDED
