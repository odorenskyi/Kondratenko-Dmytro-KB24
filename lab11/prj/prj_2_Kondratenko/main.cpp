#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include "../struct_type_project_2.h"
#include "Module_CRUD_Kondratenko.h"
#include "Module_File_Zaritskyi.h"
#include "Module_SearchDel_Kolesnyk.h"

using namespace std;

void pause() {
    cout << "\nНатисніть Enter для продовження...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void showMenu() {
    cout << "\n====================================\n";
    cout << "       Меню управління базою даних\n";
    cout << "====================================\n";
    cout << "1. Завантажити базу з файлу\n";
    cout << "2. Додати новий запис\n";
    cout << "3. Вивести всі записи\n";
    cout << "4. Зберегти базу у файл\n";
    cout << "5. Пошук за ПІБ\n";
    cout << "6. Видалити запис за табельним номером\n";
    cout << "0. Вихід\n";
    cout << "====================================\n";
    cout << "Ваш вибір: ";
}

int main() {
    Node* head = nullptr;
    int choice;
    string filename = "database.bin";

    do {
        showMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                cout << "\n Завантаження бази..." << endl;
                loadDatabase(head, filename);
                this_thread::sleep_for(chrono::milliseconds(600));
                pause();
                break;

            case 2:
                cout << "\n Додавання нового запису..." << endl;
                addRecord(head);
                this_thread::sleep_for(chrono::milliseconds(400));
                pause();
                break;

            case 3:
                cout << "\n Виведення всіх записів:\n";
                printAllRecords(head);
                pause();
                break;

            case 4:
                cout << "\n Збереження бази у файл..." << endl;
                saveDatabase(head, filename);
                this_thread::sleep_for(chrono::milliseconds(500));
                pause();
                break;

            case 5: {
                string searchName;
                cout << "\n Введіть ПІБ для пошуку: ";
                getline(cin, searchName);
                findRecordByName(head, searchName);
                pause();
                break;
            }

            case 6: {
                int id;
                cout << "\n Введіть табельний номер для видалення: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                deleteRecord(head, id);
                pause();
                break;
            }

            case 0:
                cout << "\n Вихід з програми. До побачення!" << endl;
                break;

            default:
                cout << "\n Невідомий вибір. Спробуйте ще раз." << endl;
                pause();
                break;
        }

    } while (choice != 0);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
