#include <iostream>
#include <clocale>
#include <iomanip>
#include "../ModulesKondratenko.h"

using namespace std;

// ������� ��� ��������� ���������� ��� ����������.
void SW_Developer(){

    setlocale(LC_ALL, "ukr");
    cout << "=========================================" << endl;
    cout << " Dmytro Kondratenko, yeq29880@gmail.com  " << endl;
    cout << " ������ �����������, yeq29880@gmail.com  " << endl;
    cout << "==========(c)All Rights Reserved=========" << endl;

}
// ������� ��� �������� ������ a + 7 = b.
void check_expression(char a, char b) {

    cout << "�������� ������: a + 7 == b" << endl;
    cout << "a = " << a << ", b = " << b << "" << endl;

    bool result = (a + 7 == b);
    cout << "���������: " << (result ? "true" : "false") << endl;

}
// ������� ��� ���������� �� ��������� "S" � ��������� �� �������������� ��������.
void calculate(double x, double y, double z){

    double S = s_calculation(x, y ,z);
    cout << "S � ��������� ������: " << S << endl;
    cout << "S � �������������� ������: " << hexfloat << S << defaultfloat << endl;

}


int main(){

    SW_Developer();

    double x, y, z;
    char a, b;
    cout << "������ �������� x, y, z" << endl;
    cin  >> x >> y >> z;
    calculate(x, y, z);
    cout << "������ ������� a, b" << endl;
    cin >> a >> b;
    check_expression(a, b);



}


