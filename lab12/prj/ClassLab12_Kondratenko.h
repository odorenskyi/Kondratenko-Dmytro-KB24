#ifndef CLASSLAB12_KONDRATENKO_H_INCLUDED
#define CLASSLAB12_KONDRATENKO_H_INCLUDED

#include <stdexcept>

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

#endif // CLASSLAB12_KONDRATENKO_H_INCLUDED

