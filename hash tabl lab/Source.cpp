#include <iostream>
#include "HASH_TABLE.h"

void show_menu() {
    std::cout << "\nМЕНЮ:\n";
    std::cout << "1. Показать частоту служебных слов\n";
    std::cout << "2. Найти слово в таблице\n";
    std::cout << "3. Сохранить результаты в файл\n";
    std::cout << "4. Удалить слово из таблицы\n";
    std::cout << "5. Добавить слово в таблицу\n";
    std::cout << "6. Выйти\n";

    std::cout << "Выберите действие: ";
}

int get_choice() {
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Некорректный ввод! Попробуйте снова: ";
        }
        else if (choice < 1 || choice > 6) {
            std::cout << "Пожалуйста, выберите число от 1 до 6.\n";
        }
        else {
            return choice;
        }
    }
}

std::string get_word_input() {
    std::string word;
    std::cin >> word;
    return word;
}

int main() {
    setlocale(LC_ALL, "ru");
    std::string input_file = "input.txt";
    std::string output_file = "output.txt";

    HASH_TABLE hash_table(input_file);

    while (true) {
        show_menu();
        int choice = get_choice(); 

        if (choice == 1) {
            hash_table.print();
        }
        else if (choice == 2) {
            std::cout << "Введите слово: ";
            std::string word = get_word_input(); 
            int count = hash_table.get(word);
            std::cout << "Слово '" << word << "' встречается " << count << " раз(а)." << std::endl;
        }
        else if (choice == 3) {
            hash_table.save_to_file(output_file);
            std::cout << "Результаты сохранены в " << output_file << std::endl;
        }
        else if (choice == 4) {
            std::cout << "Введите слово: ";
            std::string word = get_word_input(); 
            hash_table.remove(word);
            std::cout << "Слово удалено...\n";
        }
        else if (choice == 6) {
            std::cout << "Выход...\n";
            break;
        }
        else if (choice == 5) {
            std::cout << "Введите слово: ";
            std::string word = get_word_input(); 
            hash_table.insert(word);
            std::cout << "Слово добавлено\n";
        }
    }

    return 0;
}
