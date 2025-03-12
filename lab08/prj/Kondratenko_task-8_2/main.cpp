#include <iostream>
#include <clocale>
#include <iomanip>
#include "../ModulesKondratenko.h"

using namespace std;

// Функція для виведення інформації про розробника.
void SW_Developer(){

    setlocale(LC_ALL, "ukr");
    cout << "=========================================" << endl;
    cout << " Dmytro Kondratenko, yeq29880@gmail.com  " << endl;
    cout << " Дмитро Кондратенко, yeq29880@gmail.com  " << endl;
    cout << "==========(c)All Rights Reserved=========" << endl;

}
// Функція для перевірки рівності a + 7 = b.
void check_expression(char a, char b) {

    cout << "Перевірка виразу: a + 7 == b" << endl;
    cout << "a = " << a << ", b = " << b << "" << endl;

    bool result = (a + 7 == b);
    cout << "Результат: " << (result ? "true" : "false") << endl;

}
// Функція для обчислення та виведення "S" у десятковій та шістнадцятковій системах.
void calculate(double x, double y, double z){

    double S = s_calculation(x, y ,z);
    cout << "S у десятковій системі: " << S << endl;
    cout << "S у шістнадцятковій системі: " << hexfloat << S << defaultfloat << endl;

}


int main(){

    SW_Developer();

    double x, y, z;
    char a, b;
    cout << "Введіть значення x, y, z" << endl;
    cin  >> x >> y >> z;
    calculate(x, y, z);
    cout << "Введіть символи a, b" << endl;
    cin >> a >> b;
    check_expression(a, b);



}


