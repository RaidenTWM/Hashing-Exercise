#pragma once
#include <iostream>
#include <vector>

class HashTable {
private:
    template<typename K, typename T>
    struct HashNode {
        K key;
        T value;
        HashNode(const K& k, const T& v) : key(k), value(v) {}
    };
    std::vector<HashNode<const char*, int>*> table;
    std::vector<HashNode<std::string, std::string>*> fileTable;
    int capacity;
    int size;
    void resize();
public:
    HashTable();
    ~HashTable();
    void insert(const char* key, int value);
    int get(const char* key);
    void print();
    void insertFile(const std::string& fileName);
    bool getFile(const std::string& fileName, std::string& content);
    void printFile();
};