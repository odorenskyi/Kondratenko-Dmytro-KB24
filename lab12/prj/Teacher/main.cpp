#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <direct.h>
#include <thread>
#include <chrono>
#include "../../../lab08/prj/ModulesKondratenko/ModulesKondratenko.h"

using namespace std;

struct TestCase {
    string name, method, expectedValues, expectedException;
    vector<double> params, setupParams;
    double expectedValue = 0;
    bool hasException = false;
};

bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

bool checkProjectLocation() {
    char buffer[1000];
    char* path = _getcwd(buffer, sizeof(buffer));
    if (!path) return false;
    string pathStr(path);
    return pathStr.find("lab12") != string::npos && pathStr.find("prj") != string::npos;
}

void playErrorSounds() {
    cout << "Відтворення 100 звукових сигналів..." << endl;
    for (int i = 0; i < 100; i++) {
        cout << "\a";
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

vector<double> parseParams(const string& str) {
    vector<double> params;
    if (str.empty()) return params;
    stringstream ss(str);
    string param;
    while (getline(ss, param, ',')) {
        params.push_back(stod(param));
    }
    return params;
}

vector<TestCase> readTests(const string& filename) {
    vector<TestCase> tests;
    ifstream file(filename);
    if (!file.is_open()) return tests;

    string line;
    TestCase test;
    bool reading = false;

    while (getline(file, line)) {
        if (line.find("TEST_CASE:") == 0) {
            if (reading) tests.push_back(test);
            test = TestCase();
            test.name = line.substr(11);
            reading = true;
        }
        else if (line.find("METHOD:") == 0) test.method = line.substr(8);
        else if (line.find("PARAMS:") == 0) {
            string paramStr = line.substr(8);
            if (paramStr.find("setup:") == 0) {
                test.setupParams = parseParams(paramStr.substr(6));
            } else {
                test.params = parseParams(paramStr);
            }
        }
        else if (line.find("EXPECTED:") == 0) {
            string exp = line.substr(10);
            if (exp.find("=") != string::npos) {
                test.expectedValues = exp;
            } else {
                test.expectedValue = stod(exp);
            }
        }
        else if (line.find("EXCEPTION:") == 0) {
            test.expectedException = line.substr(11);
            test.hasException = true;
        }
        else if (line == "---" && reading) {
            tests.push_back(test);
            reading = false;
        }
    }
    if (reading) tests.push_back(test);
    return tests;
}

bool runTest(const TestCase& test, ofstream& log) {
    log << "Тест: " << test.name << " | Метод: " << test.method << endl;

    try {
        ClassLab12_Kondratenko obj;

        // Налаштування об'єкта
        if (test.setupParams.size() >= 3) {
            obj = ClassLab12_Kondratenko(test.setupParams[0], test.setupParams[1], test.setupParams[2]);
        }

        // Виконання тесту
        if (test.method == "constructor_default") {
            ClassLab12_Kondratenko defaultObj;
            bool ok = (defaultObj.getHeight() == 1.0 && defaultObj.getWidth() == 1.0 && defaultObj.getLength() == 1.0);
            log << "Результат: " << (ok ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
            return ok;
        }
        else if (test.method == "constructor_params" && test.params.size() >= 3) {
            ClassLab12_Kondratenko paramObj(test.params[0], test.params[1], test.params[2]);
            bool ok = (paramObj.getHeight() == test.params[0] &&
                      paramObj.getWidth() == test.params[2] &&
                      paramObj.getLength() == test.params[1]);
            log << "Результат: " << (ok ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
            return ok;
        }
        else if (test.method == "setHeight" && test.params.size() >= 1) {
            obj.setHeight(test.params[0]);
            bool ok = (obj.getHeight() == test.params[0]);
            log << "Результат: " << (ok ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
            return ok;
        }
        else if (test.method == "setWidth" && test.params.size() >= 1) {
            obj.setWidth(test.params[0]);
            bool ok = (obj.getWidth() == test.params[0]);
            log << "Результат: " << (ok ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
            return ok;
        }
        else if (test.method == "setLength" && test.params.size() >= 1) {
            obj.setLength(test.params[0]);
            bool ok = (obj.getLength() == test.params[0]);
            log << "Результат: " << (ok ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
            return ok;
        }
        else if (test.method == "getVolume") {
            double volume = obj.getVolume();
            bool ok = (abs(volume - test.expectedValue) < 1e-9);
            log << "Обчислено: " << volume << " | Очікувано: " << test.expectedValue << endl;
            log << "Результат: " << (ok ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
            return ok;
        }
    }
    catch (const exception& e) {
        if (test.hasException && string(e.what()).find(test.expectedException) != string::npos) {
            log << "Очікуваний виняток: " << e.what() << endl;
            log << "Результат: ПРОЙДЕНО" << endl;
            return true;
        } else {
            log << "Неочікуваний виняток: " << e.what() << endl;
            log << "Результат: НЕ ПРОЙДЕНО" << endl;
            return false;
        }
    }

    log << "Результат: НЕ ПРОЙДЕНО" << endl;
    return false;
}

int main() {
    cout << "=== TEACHER APPLICATION ===" << endl;

    char buffer[1000];
    cout << "Поточна директорія: " << (_getcwd(buffer, sizeof(buffer)) ? buffer : "невідома") << endl;

    if (!checkProjectLocation()) {
        cout << "ПОМИЛКА: Неправильне розташування файлу!" << endl;
        playErrorSounds();
        ofstream file("TestResults.txt");
        file << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        file.close();
        return 1;
    }

    cout << "Розташування коректне. Запуск тестування..." << endl;

    string testDir = "../../TestSuite/";
    if (!fileExists(testDir + "constructor_tests.txt")) {
        cout << "Помилка: Тест-файли не знайдено!" << endl;
        return 1;
    }

    vector<string> testFiles = {
        "constructor_tests.txt", "setter_tests.txt", "volume_tests.txt"
    };

    ofstream log(testDir + "TestResults.txt");
    log << "=== РЕЗУЛЬТАТИ UNIT-ТЕСТУВАННЯ ===" << endl << endl;

    int total = 0, passed = 0;

    for (const string& file : testFiles) {
        cout << "Обробка: " << file << endl;
        vector<TestCase> tests = readTests(testDir + file);

        for (const TestCase& test : tests) {
            total++;
            if (runTest(test, log)) passed++;
            log << "---" << endl;
        }
    }

    log << endl << "ПІДСУМОК: " << passed << "/" << total << " тестів пройдено ("
        << (total > 0 ? passed * 100 / total : 0) << "%)" << endl;

    cout << "Тестування завершено. Результати в TestResults.txt" << endl;
    cout << "Підсумок: " << passed << "/" << total << " тестів пройдено" << endl;

    return 0;
}
