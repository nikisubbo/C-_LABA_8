#include <iostream>
int main() {
    setlocale(LC_ALL, "");
    int choice = 0;
    std::string menu_message = "Меню:1)Dynamic4\n2)Dynamic26\n3)ListWork13\n4)ListWork22\n5)ListWork60\n6)Выход\nВведите номер выбранного пункта меню: ";
    std::cout << menu_message;
    std::cin >> choice;
    while (choice != 6) {
        if (choice < 1 || choice > 6) {
            std::cout << "Ошибка. Некорректный ввод, попробуйте еще раз: " << std::endl;
        }
        else {
            switch (choice) {
            case 1:
                Dynamic4();
                break;
            case 2:
                Dynamic26();
                break;
            case 3:
                ListWork13();
                break;
            case 4:
                ListWork22();
                break;
            case 5:
                ListWork60();
                break;
            }
        }
        std::cout << menu_message;
        std::cin >> choice;
    }
    std::cout << "Завершение работы..." << std::endl;
    return 0;
}
