#include <iostream>
#include "HASH_TABLE.h"



void show_menu() {
    std::cout << "\n����:\n";
    std::cout << "1. �������� ������� ��������� ����\n";
    std::cout << "2. ����� ����� � �������\n";
    std::cout << "3. ��������� ���������� � ����\n";
    std::cout << "4. �����\n";
    std::cout << "�������� ��������: ";
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
            std::cout << "������� �����: ";
            std::string word;
            std::cin >> word;
            int count = hash_table.get(word);
            std::cout << "����� '" << word << "' ����������� " << count << " ���(�)." << std::endl;
        }
        else if (choice == 3) {
            hash_table.save_to_file(output_file);
            std::cout << "���������� ��������� � " << output_file << std::endl;
        }
        else if (choice == 4) {
            std::cout << "�����...\n";
            break;
        }
        else {
            std::cout << "������������ ����! ���������� �����.\n";
        }
    }

    return 0;
}
