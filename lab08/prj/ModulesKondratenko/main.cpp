#include <iostream>
#include <cmath>
#include <bitset>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>


using namespace std;

double s_calculation(double x, double y, double z){
    return fabs(abs(sin(y - pow(z, 2 ))) + sqrt(x) - sqrt(pow((y * z), x) + y / (2 * M_PI)));


}

double salary_calculation(double salary, int experience, double office_salary){

    double bonus = 0.0;

    if(experience >= 3 && experience <= 5)
            bonus = office_salary * 0.10;
    else if(experience >= 5 && experience <=7)
            bonus = office_salary * 0.15;
    else if(experience >= 7 && experience <= 15)
            bonus = office_salary * 0.20;
    else if(experience > 15)
            bonus = office_salary * 0.25;

    return salary + bonus;
}

void temperature_calculation(const double temps[], int size, double& avg_celsius, double& avg_fahrenheit){

    double sum = 0.0;;
    for (int i = 0; i < size; ++i)
        sum += temps[i];
    avg_celsius = sum / size;
    avg_fahrenheit = 32 + (9.0/5.0) *avg_celsius;

}

double analyze_bit(unsigned int N){

        int bit11 = (N >> 11) & 1;
        int count = 0;
        for(int i = 0; i < 32; ++i){
            count += (((N >> i) & 1) == bit11) ? 1 : 0;
        }
        return count;

}


string getAuthorInfo() {
    return "Розробник: Кондратенко Дмитро, Центральноукраїнський Національний Технічний Університет, Кропивницький, Україна, 2025\n";
}

string extractUppercase(const string& filename) {
    ifstream file(filename);
    string line, result;
    while (getline(file, line)) {
        for (char ch : line) {
            if (isupper(static_cast<unsigned char>(ch))) {
                result += ch;
            }
        }
    }
    return "Великі літери з тексту: " + result + "\n";
}

string checkPunctuation(const string& filename) {
    ifstream file(filename);
    string line;
    int lineNum = 0;
    string result = "Перевірка розділових знаків:\n";

    while (getline(file, line)) {
        lineNum++;
        char lastChar = line.empty() ? ' ' : line.back();
        if (lastChar == '.' || lastChar == ',' || lastChar == ';' || lastChar == ':' || lastChar == '!' || lastChar == '?') {
            result += "Рядок " + to_string(lineNum) + ": закінчується розділовим знаком\n";
        } else {
            result += "Рядок " + to_string(lineNum) + ": НЕ закінчується розділовим знаком\n";
        }
    }

    return result + "\n";
}

void writePoemVertically(const string& inputFile, const string& outputFile) {
    ifstream file(inputFile);
    string lines[4];
    for (int i = 0; i < 4 && getline(file, lines[i]); i++) {}

    ofstream out(outputFile, ios::app);
    out << "Вірш у стовпчик:\n";
    size_t maxLen = 0;
    for (const auto& l : lines) maxLen = max(maxLen, l.length());

    for (size_t i = 0; i < maxLen; i++) {
        for (int j = 0; j < 4; j++) {
            if (i < lines[j].length()) {
                out << lines[j][i] << "   ";
            } else {
                out << "    ";
            }
        }
        out << "\n";
    }
}

string getFileSizeKB(const string& filename) {
    ifstream in(filename, ios::binary | ios::ate);
    streamsize size = in.tellg();
    in.close();
    return "Розмір файлу: " + to_string(size / 1024.0) + " KB\n";
}


string getCurrentDateTime() {
    time_t now = time(0);
    string dt = ctime(&now);
    return "Дата і час: " + dt + "\n";
}


string toBinary(int b) {
    return bitset<16>(b).to_string();
}
