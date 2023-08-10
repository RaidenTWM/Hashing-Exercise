#pragma once
#include <iostream>
#include <vector>

class HashTable {
private:
    struct HashNode {
        const char* key;
        int value;
        HashNode(const char* k, int v) : key(k), value(v) {}
    };
    std::vector<HashNode*> table;
    int capacity;
    int size;
    void resize();
public:
    HashTable();
    ~HashTable();
    void insert(const char* key, int value);
    int get(const char* key);
    void print();
};