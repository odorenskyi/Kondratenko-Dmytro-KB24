#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;


double s_calculation(double x, double y, double z){
    return fabs(abs(sin(y - pow(z, 2 ))) + sqrt(x) - sqrt(pow((y * z), x) + y / (2 * M_PI)));


}

double salary_calculation(double salary, int experience, double office_salary){

    double bonus = 0.0;

    if(experience >= 3 && experience <= 5)
            bonus = office_salary * 0.10;
    else if(experience >= 5 && experience <=7)
            bonus = office_salary * 0.15;
    else if(experience >= 7 && experience <= 15)
            bonus = office_salary * 0.20;
    else if(experience > 15)
            bonus = office_salary * 0.25;

    return salary + bonus;
}

void temperature_calculation(const double temps[], int size, double& avg_celsius, double& avg_fahrenheit){

    double sum = 0.0;;
    for (int i = 0; i < size; ++i)
        sum += temps[i];
    avg_celsius = sum / size;
    avg_fahrenheit = 32 + (9.0/5.0) *avg_celsius;

}

double analyze_bit(unsigned int N){

        int bit11 = (N >> 11) & 1;
        int count = 0;
        for(int i = 0; i < 32; ++i){
            count += (((N >> i) & 1) == bit11) ? 1 : 0;
        }
        return count;

}
