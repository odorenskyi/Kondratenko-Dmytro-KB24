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

class ClassLab12_Kondratenko {

public:
    ClassLab12_Kondratenko() : height(1), width(1), length(1) {}

    ClassLab12_Kondratenko(double h, double l, double w) {
        setHeight(h);
        setLength(l);
        setWidth(w);
    }

    double getHeight() const { return height; }
    double getLength() const { return length; }
    double getWidth() const { return width; }

    void setHeight(double h) {
        if (h < 0) throw std::invalid_argument("Висота прямокутника не може бути менше нуля!");
        height = h;
    }

    void setLength(double l) {
        if (l < 0) throw std::invalid_argument("Довжина прямокутника не може бути менше нуля!");
        length = l;
    }

    void setWidth(double w) {
        if (w < 0) throw std::invalid_argument("Ширина прямокутника не може бути менше нуля!");
        width = w;
    }

    double getVolume() const {
        return height * width * length;
    }

private:
    double height;
    double width;
    double length;

};

#endif // MODULESKONDRATENKO_H_INCLUDED
