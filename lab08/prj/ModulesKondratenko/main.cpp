#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;


double s_calculation(double x, double y, double z){
    return fabs(abs(sin(y - pow(z, 2 ))) + sqrt(x) - sqrt(pow((y * z), x) + y / (2 * M_PI)));


}

double salary_calculation(double salary, double experience, double office_salary, double result_salary){
    cout << "¬вед≥ть розм≥р зароб≥тноњ плати(грн): " << endl;
    cin >> salary;
    cout << "¬вед≥ть розм≥р посадового окладу(грн): " << endl;
    cin >> office_salary;
    cout << "¬вед≥ть стаж роботи на п≥дприЇмств≥(роки): " << endl;
    cin >> experience;

    if(experience >= 3 && experience <= 5) {
            office_salary * 10/100;
    }
    else if(experience >= 5 && experience <=7){
            office_salary * 15/100;
    }
    else if(experience >= 7 && experience <= 15){
            office_salary * 20/100;
    }
    else if(experience > 15) {
            office_salary * 25/100;
    }

    result_salary = salary + office_salary;

    cout << "—ума до виплати = " << result_salary << endl;

}

void temperature_calculation(double avg_celsius, int size, double avg_fahrenheit, const double temps[]){

    double sum = 0.0;
    cout << "¬вед≥ть температуру(у ∞C) в 00:00, 04:00, 08:00, 12:00, 16:00, 20:00 почергово: " << endl;
    for (int i = 0; i < size; ++i) {
        sum += temps[i];
    }

    avg_celsius = sum / size;
    avg_fahrenheit = 32 + (9.0/5.0) *avg_celsius;
}

double analyze_bit(unsigned int N){

        int bit11 = (N >> 11) & 1;
        int count = 0;
        bitset<32> bits(N);
        for(int i = 0; i < 32; ++i){
            if(bit11 == 0 && bits[i] == 0) count++;
            if(bit11 == 1 && bits[i] == 1) count++;
        }
        return count;

}
