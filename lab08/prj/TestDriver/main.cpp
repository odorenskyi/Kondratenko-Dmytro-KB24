#include <iostream>
#include <clocale>
#include "../ModulesKondratenko.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "ukr");
    cout << "=========================================" << endl;
    cout << " Dmytro Kondratenko, yeq29880@gmail.com  " << endl;
    cout << " ������ �����������, yeq29880@gmail.com  " << endl;
    cout << "==========(c)All Rights Reserved=========" << endl;

    double x, y, z;
    cout << "������ �������� x, y, z: " << endl;
    cin >> x >> y >> z;

    double S = s_calculation(x, y, z);

    cout << "�������� S = " << S << endl;

    return 0;
}
