#include <iostream>
#include "HASH_TABLE.h"



void show_menu() {
    std::cout << "\nМЕНЮ:\n";
    std::cout << "1. Показать частоту служебных слов\n";
    std::cout << "2. Найти слово в таблице\n";
    std::cout << "3. Сохранить результаты в файл\n";
    std::cout << "4. Выйти\n";
    std::cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "ru");
    std::string input_file = "input.txt";
    std::string output_file = "output.txt";

    HASH_TABLE hash_table(input_file);

    while (true) {
        show_menu();
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            hash_table.print();
        }
        else if (choice == 2) {
            std::cout << "Введите слово: ";
            std::string word;
            std::cin >> word;
            int count = hash_table.get(word);
            std::cout << "Слово '" << word << "' встречается " << count << " раз(а)." << std::endl;
        }
        else if (choice == 3) {
            hash_table.save_to_file(output_file);
            std::cout << "Результаты сохранены в " << output_file << std::endl;
        }
        else if (choice == 4) {
            std::cout << "Выход...\n";
            break;
        }
        else {
            std::cout << "Некорректный ввод! Попробуйте снова.\n";
        }
    }

    return 0;
}
