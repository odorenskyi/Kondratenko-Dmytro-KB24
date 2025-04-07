#include <iostream>
#include "ModulesKondratenko.h"\
#include <clocale>

using namespace std;

void test_salary() {
    cout << "--- Тест задачі 9.1 ---\n";
    struct {
        double salary;
        int experience;
        double office_salary;
        double expected;
    } tests[] = {
        {10000, 4, 8000, 10000 + 800},
        {12000, 6, 10000, 12000 + 1500},
        {9000, 10, 7000, 9000 + 1400}
    };

    for (auto& t : tests) {
        double result = salary_calculation(t.salary, t.experience, t.office_salary);
        cout << "ЗП: " << t.salary << ", Стаж: " << t.experience << ", Оклад: " << t.office_salary
             << " -> Результат: " << result << " | Очікується: " << t.expected;
        cout << (abs(result - t.expected) < 1e-2 ? "  Passed\n" : "  Failed\n");
    }
}

void test_temperature() {
    cout << "\n--- Тест задачі 9.2 ---\n";
    struct {
        double temps[6];
        double expected_c;
        double expected_f;
    } tests[] = {
        {{10.0, 12.0, 15.0, 18.0, 17.0, 14.0}, 14.3333, 32 + (9.0/5.0) * 14.3333},
        {{5.0, 5.0, 5.0, 5.0, 5.0, 5.0}, 5.0, 32 + (9.0/5.0) * 5.0},
        {{20.0, 22.0, 19.0, 21.0, 23.0, 18.0}, 20.5, 32 + (9.0/5.0) * 20.5}
    };

    for (int i = 0; i < 3; ++i) {
        double avg_c = 0.0, avg_f = 0.0;
        temperature_calculation(tests[i].temps, 6, avg_c, avg_f);

        cout << "\nТест " << i+1 << ":\n";
        cout << "Очікувана °C: " << tests[i].expected_c << ", Отримана: " << avg_c
             << (fabs(avg_c - tests[i].expected_c) < 1e-2 ? "  Passed\n" : "  Failed\n");

        cout << "Очікувана °F: " << tests[i].expected_f << ", Отримана: " << avg_f
             << (fabs(avg_f - tests[i].expected_f) < 1e-2 ? "  Passed\n" : "  Failed\n");
    }
}

void test_bits() {
    cout << "\n--- Тест задачі 9.3 ---\n";
    struct {
        unsigned int N;
        int expected;
    } tests[] = {
        {0b0000100000000000, 1},
        {0b0000100000001000, 2},
        {0b0000100001001000, 3}
    };

    for (auto& t : tests) {
        int result = analyze_bit(t.N);
        cout << "Число: " << t.N << " -> Результат: " << result << " | Очікується: " << t.expected;
        cout << (result == t.expected ? "  Passed\n" : "  Failed\n");
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    test_salary();
    test_temperature();
    test_bits();
    return 0;

}
