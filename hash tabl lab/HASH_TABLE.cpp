#include "HASH_TABLE.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


const std::vector<std::string> PASCAL_KEYWORDS = {
	"and", "array", "begin", "case", "const", "div", "do", "downto", "else",
	"end", "file", "for", "function", "goto", "if", "in", "label", "mod",
	"nil", "not", "of", "or", "packed", "procedure", "program", "record",
	"repeat", "set", "then", "to", "type", "until", "var", "while", "with"
};

std::string to_lower(const std::string& str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

HASH_NODE::HASH_NODE(const std::string& key, int value) : key(key), value(value), next(nullptr) {}

HASH_NODE::~HASH_NODE() {}

// Хеш-функция (сумма ASCII-кодов символов по модулю размера таблицы)
// В данной хеш-таблице коллизии решаются методом цепочек
int HASH_TABLE::hash_func(const std::string& key) const
{
	int hash = 0;
	for (char ch : key)
		hash = (hash * 31 + ch) % SIZE;
	return hash;
}


HASH_TABLE::HASH_TABLE(const std::string& fname) {
	for (int i = 0; i < SIZE; i++)
		table[i] = nullptr;

	std::ifstream file(fname);
	if (!file) {
		std::cout << "Ошибка: Не удалось открыть файл " << fname << std::endl;
		return;
	}

	std::string word;
	while (file >> word) {
		word = to_lower(word);
		if (find(PASCAL_KEYWORDS.begin(), PASCAL_KEYWORDS.end(), word) != PASCAL_KEYWORDS.end()) {
			insert(word);
		}
	}
}

HASH_TABLE::~HASH_TABLE() {
	clear();
}

void HASH_TABLE::clear() {
	for (int i = 0; i < SIZE; i++) {
		HASH_NODE* entry = table[i];
		while (entry) {
			HASH_NODE* temp = entry;
			entry = entry->next;
			delete temp;
		}
		table[i] = nullptr;
	}
}




void HASH_TABLE::insert(const std::string& key)
{
	int hash_index = hash_func(key);
	HASH_NODE* entry = table[hash_index];
	while (entry)
	{
		if (entry->key == key)
		{
			entry->value++;
			return;
		}
		entry = entry->next;
	}

	entry = new HASH_NODE(key, 1);
	entry->next = table[hash_index];
	table[hash_index] = entry;
}

int HASH_TABLE::get(const std::string& key) const
{
	int hash_index = hash_func(key);
	HASH_NODE* entry = table[hash_index];

	while (entry) {
		if (entry->key == key)
			return entry->value;
		entry = entry->next;
	}
	return 0;
}

void HASH_TABLE::print() const
{
	for (int i = 0; i < SIZE; i++) {
		HASH_NODE* entry = table[i];
		while (entry) {
			std::cout << entry->key << ": " << entry->value << std::endl;
			entry = entry->next;
		}
	}
}

void HASH_TABLE::save_to_file(const std::string& fname) const
{
	std::ofstream file(fname);
	if (!file) {
		std::cout << "Ошибка: не удалось открыть " << fname << std::endl;
		return;
	}

	for (int i = 0; i < SIZE; i++) {
		HASH_NODE* entry = table[i];
		while (entry) {
			file << entry->key << " " << entry->value << std::endl;
			entry = entry->next;
		}
	}

	file.close();
}




