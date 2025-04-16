#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cmath>
#include "../../../lab08/prj/ModulesKondratenko/ModulesKondratenko.h"

using namespace std;

void test_10_1() {
    cout << "\n===== ���� 10.1: ������ � ������� =====\n";

    ofstream input("input.txt");
    input << "�� ������ �����,\n"
          << "�� ��� �����.\n"
          << "����� ������� ����,\n"
          << "� ³��� ������.\n";
    input.close();
    cout << "[INFO] ������� ���� input.txt ��������.\n";

    ofstream clearOut("output.txt");
    clearOut.close();
    cout << "[INFO] �������� ���� output.txt �������.\n";

    ofstream out("output.txt", ios::app);
    string author = getAuthorInfo();
    string uppercase = extractUppercase("input.txt");
    string punctuation = checkPunctuation("input.txt");

    cout << "[] ��������� ����������:\n" << author;
    cout << "[] ����� �����: " << uppercase;
    cout << "[] �������� ����������:\n" << punctuation;

    out << author;
    out << uppercase;
    out << punctuation;
    out.close();

    writePoemVertically("input.txt", "output.txt");
    cout << "[INFO] ³�� �������� � ������������� ������.\n";

    cout << "[Test 10.1]  ������ ���������\n";
}

void test_10_2() {
    cout << "\n===== ���� 10.2: ����� ������ �� ���� =====\n";

    string fileSize = getFileSizeKB("output.txt");
    string dateTime = getCurrentDateTime();

    cout << " ����� �����: " << fileSize;
    cout << " ���� � ���: " << dateTime;

    ofstream out("output.txt", ios::app);
    out << fileSize;
    out << dateTime;
    out.close();

    cout << "[Test 10.2]  ������ ���������\n";
}

void test_10_3() {
    cout << "\n===== ���� 10.3: ���������� ������� �� ������� ������� =====\n";

    struct TestCase {
    int x, y, z, b;
};
    TestCase test1 = {4, 2, 3, 2};
    TestCase test2 = {16, 3, 1, 8};
    TestCase test3 = {9, 1, 2, 1};

    ofstream out("output.txt", ios::app);

    double result1 = s_calculation(test1.x, test1.y, test1.z);
    string binary1 = toBinary(test1.b);
    cout << "Test 1: s_calculation(" << test1.x << ", " << test1.y << ", " << test1.z << ") = " << result1 << endl;
    cout << " toBinary(" << test1.b << ") = " << binary1 << endl;
    out << "Test 1:\n��������� ����������: " << result1 << "\n����� b � ������� ����: " << binary1 << "\n";

    double result2 = s_calculation(test2.x, test2.y, test2.z);
    string binary2 = toBinary(test2.b);
    cout << " Test 2: s_calculation(" << test2.x << ", " << test2.y << ", " << test2.z << ") = " << result2 << endl;
    cout << " toBinary(" << test2.b << ") = " << binary2 << endl;
    out << "Test 2:\n��������� ����������: " << result2 << "\n����� b � ������� ����: " << binary2 << "\n";

    double result3 = s_calculation(test3.x, test3.y, test3.z);
    string binary3 = toBinary(test3.b);
    cout << " Test 3: s_calculation(" << test3.x << ", " << test3.y << ", " << test3.z << ") = " << result3 << endl;
    cout << " toBinary(" << test3.b << ") = " << binary3 << endl;
    out << "Test 3:\n��������� ����������: " << result3 << "\n����� b � ������� ����: " << binary3 << "\n";

    out.close();
    cout << "[Test 10.3] ������ ���������\n";
}


int main() {
    setlocale(LC_ALL, "Ukrainian");
    setlocale(LC_ALL, "uk_UA.UTF-8");

    cout << "=== ����������� ���������� ����������� �10 ===\n";
    test_10_1();
    test_10_2();
    test_10_3();
    cout << "\n �� ����� �������� ������!\n";

    return 0;
}
