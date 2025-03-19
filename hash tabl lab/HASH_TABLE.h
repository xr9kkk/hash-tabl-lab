#pragma once

#include <string>

class HASH_NODE
{
public:
	std::string key;
	int value;
	HASH_NODE* next;

	HASH_NODE(const std::string& key, int value);
	~HASH_NODE();
};

class HASH_TABLE
{
private:
	
	static const int SIZE = 101;
	HASH_NODE* table[SIZE];

	int hash_func(const std::string& key) const;

public:

	HASH_TABLE(const std::string& fname);
	~HASH_TABLE();

	void clear();
	void insert(const std::string& key);
	int get(const std::string& key) const;
	void print() const;
	void save_to_file(const std::string& fname) const;
};

