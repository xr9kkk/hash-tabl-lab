#include <iostream>
#include "HASH_TABLE.h"

void show_menu() {
    std::cout << "\n����:\n";
    std::cout << "1. �������� ������� ��������� ����\n";
    std::cout << "2. ����� ����� � �������\n";
    std::cout << "3. ��������� ���������� � ����\n";
    std::cout << "4. ������� ����� �� �������\n";
    std::cout << "5. �������� ����� � �������\n";
    std::cout << "6. �����\n";

    std::cout << "�������� ��������: ";
}

int get_choice() {
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "������������ ����! ���������� �����: ";
        }
        else if (choice < 1 || choice > 6) {
            std::cout << "����������, �������� ����� �� 1 �� 6.\n";
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
            std::cout << "������� �����: ";
            std::string word = get_word_input(); 
            int count = hash_table.get(word);
            std::cout << "����� '" << word << "' ����������� " << count << " ���(�)." << std::endl;
        }
        else if (choice == 3) {
            hash_table.save_to_file(output_file);
            std::cout << "���������� ��������� � " << output_file << std::endl;
        }
        else if (choice == 4) {
            std::cout << "������� �����: ";
            std::string word = get_word_input(); 
            hash_table.remove(word);
            std::cout << "����� �������...\n";
        }
        else if (choice == 6) {
            std::cout << "�����...\n";
            break;
        }
        else if (choice == 5) {
            std::cout << "������� �����: ";
            std::string word = get_word_input(); 
            hash_table.insert(word);
            std::cout << "����� ���������\n";
        }
    }

    return 0;
}
