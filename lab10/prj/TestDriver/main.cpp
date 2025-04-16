#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cmath>
#include "../../../lab08/prj/ModulesKondratenko/ModulesKondratenko.h"

using namespace std;

void test_10_1() {
    cout << "\n===== Тест 10.1: Робота з текстом =====\n";

    ofstream input("input.txt");
    input << "Ми Летимо Увись,\n"
          << "Де Сяє Сонце.\n"
          << "Світло Пронизує Небо,\n"
          << "І Вітер Шепоче.\n";
    input.close();
    cout << "[INFO] Вхідний файл input.txt створено.\n";

    ofstream clearOut("output.txt");
    clearOut.close();
    cout << "[INFO] Вихідний файл output.txt очищено.\n";

    ofstream out("output.txt", ios::app);
    string author = getAuthorInfo();
    string uppercase = extractUppercase("input.txt");
    string punctuation = checkPunctuation("input.txt");

    cout << "[] Авторська інформація:\n" << author;
    cout << "[] Великі літери: " << uppercase;
    cout << "[] Перевірка пунктуації:\n" << punctuation;

    out << author;
    out << uppercase;
    out << punctuation;
    out.close();

    writePoemVertically("input.txt", "output.txt");
    cout << "[INFO] Вірш записано у вертикальному вигляді.\n";

    cout << "[Test 10.1]  Успішно завершено\n";
}

void test_10_2() {
    cout << "\n===== Тест 10.2: Запис розміру та часу =====\n";

    string fileSize = getFileSizeKB("output.txt");
    string dateTime = getCurrentDateTime();

    cout << " Розмір файлу: " << fileSize;
    cout << " Дата і час: " << dateTime;

    ofstream out("output.txt", ios::app);
    out << fileSize;
    out << dateTime;
    out.close();

    cout << "[Test 10.2]  Успішно завершено\n";
}

void test_10_3() {
    cout << "\n===== Тест 10.3: Обчислення формули та двійкова система =====\n";

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
    out << "Test 1:\nРезультат обчислення: " << result1 << "\nЧисло b в двійковій формі: " << binary1 << "\n";

    double result2 = s_calculation(test2.x, test2.y, test2.z);
    string binary2 = toBinary(test2.b);
    cout << " Test 2: s_calculation(" << test2.x << ", " << test2.y << ", " << test2.z << ") = " << result2 << endl;
    cout << " toBinary(" << test2.b << ") = " << binary2 << endl;
    out << "Test 2:\nРезультат обчислення: " << result2 << "\nЧисло b в двійковій формі: " << binary2 << "\n";

    double result3 = s_calculation(test3.x, test3.y, test3.z);
    string binary3 = toBinary(test3.b);
    cout << " Test 3: s_calculation(" << test3.x << ", " << test3.y << ", " << test3.z << ") = " << result3 << endl;
    cout << " toBinary(" << test3.b << ") = " << binary3 << endl;
    out << "Test 3:\nРезультат обчислення: " << result3 << "\nЧисло b в двійковій формі: " << binary3 << "\n";

    out.close();
    cout << "[Test 10.3] Успішно завершено\n";
}


int main() {
    setlocale(LC_ALL, "Ukrainian");
    setlocale(LC_ALL, "uk_UA.UTF-8");

    cout << "=== Автоматичне тестування Лабораторної №10 ===\n";
    test_10_1();
    test_10_2();
    test_10_3();
    cout << "\n Усі тести пройдено успішно!\n";

    return 0;
}
