#include <iostream>
#include <cassert>
#include "../ClassLab12_Kondratenko.h"

using namespace std;

void printResult(const string& testName, bool condition) {
    cout << testName << ": " << (condition ? "passed" : "failed") << endl;
}

int main() {
    cout << "==== Тестування класу ClassLab12_Kondratenko: ====\n\n";

    // TC01: Створення об'єкта з коректними значеннями
    ClassLab12_Kondratenko obj(3, 4, 5);
    printResult("TC01 - Ініціалізація з 3,4,5", obj.getVolume() == 60);

    // TC02: Зміна довжини
    obj.setLength(6);
    printResult("TC02 - setLength(6)", obj.getLength() == 6);

    // TC03: Перевірка нового об'єму після зміни
    printResult("TC03 - Перевірка об'єму після setLength(6)", obj.getVolume() == 3 * 5 * 6);

    // TC04: Некоректна ширина
    bool caughtWidthException = false;
    try {
        obj.setWidth(-10);
    } catch (const std::invalid_argument& e) {
        caughtWidthException = true;
    }
    printResult("TC04 - setWidth(-10) викликає виняток", caughtWidthException);

    // TC05: Конструктор за замовчуванням
    ClassLab12_Kondratenko defaultObj;
    printResult("TC05 - Конструктор за замовчуванням", defaultObj.getVolume() == 1);

    cout << "\n==== Тестування завершено. ====\n";
    return 0;
}
