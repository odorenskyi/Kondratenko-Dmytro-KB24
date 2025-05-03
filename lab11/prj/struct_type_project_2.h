#ifndef STRUCT_TYPE_PROJECT_2_H_INCLUDED
#define STRUCT_TYPE_PROJECT_2_H_INCLUDED

#include <string>
#include <chrono>

using namespace std;

struct EmployeeRecord {
    chrono::year_month_day date_filled;    // ���� ����������
    int employee_id;                            // ��������� �����
    string tax_id;                              // ���������������� �����
    enum class Gender { M, F, Other } gender;   // �����
    string work_type;                           // ��� ������
    string full_name;                           // ϲ� ����������
    chrono::year_month_day birth_date;          // ���� ����������
    string citizenship;                         // ������������
    string education;                           // �����
    string last_job;                            // ������ ���� ������
    string last_position;                       // ������� ������
    short int exp_days, exp_months, exp_years;  // ���� ������ (���/������/����)
    string address;                             // ̳��� ����������
    string passport;                            // �������� ���
    string notes;                               // �������� �������
    chrono::year_month_day dismissal_date;      // ���� ���������
    string dismissal_reason;                    // ������� ���������
};

struct Node {
    EmployeeRecord record;
    Node* next;
};


#endif // STRUCT_TYPE_PROJECT_2_H_INCLUDED
