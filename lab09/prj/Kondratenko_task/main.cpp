#include <iostream>
#include <cctype>
#include <limits>
#include <clocale>
#include "ModulesKondratenko.h"

using namespace std;

void run_task() {
    char command;
    while (true) {
        cout << "\n������ ������� ('z', 'r', 's', 't') ��� 'q' ��� ������: ";
        cin >> command;

        switch (tolower(command)) {
            case 'z': {
                double x, y, z;
                cout << "������ x, y, z ��� ���������� S: ";
                cin >> x >> y >> z;
                double result = s_calculation(x, y, z);
                cout << "��������� ���������� s_calculation: " << result << endl;
                break;
            }
            case 'r': {
                double salary, office_salary;
                int experience;
                cout << "������ �������� �����, ��������� ����� � ����: ";
                cin >> salary >> office_salary >> experience;
                double result = salary_calculation(salary, experience, office_salary);
                cout << "���� �� �������: " << result << " ���\n";
                break;
            }
            case 's': {
                double temps[6];
                cout << "������ ����������� (00:00, 04:00, 08:00, 12:00, 16:00, 20:00): ";
                for (int i = 0; i < 6; ++i) {
                    cin >> temps[i];
                }
                double avg_c, avg_f;
                temperature_calculation(temps, 6, avg_c, avg_f);
                cout << "������� �����������: " << avg_c << " �C, " << avg_f << " �F\n";
                break;
            }
            case 't': {
                unsigned int N;
                cout << "������ ���������� ����� N: ";
                cin >> N;
                int count = analyze_bit(N);
                cout << "��������� ������ ���: " << count << endl;
                break;
            }
            case 'q':
                cout << "���������� ��������.\n";
                return;
            default:
                cout << "\a������ �������! �������� ��������.\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    run_task();
    return 0;
};
