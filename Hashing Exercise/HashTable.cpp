#include "HashTable.h"
#include "HashFunction.h"
#include <fstream>

HashTable::HashTable() {
    capacity = 8;
    size = 0;
    table.resize(capacity, nullptr);
    fileTable.resize(capacity, nullptr);
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        delete table[i];
        table[i] = nullptr;
    }
}

void HashTable::insert(const char* key, int value) {
    size_t index = HashFunction::Default(key, sizeof(key)) % capacity;

    while (table[index] != nullptr && table[index]->key != key) {
        index = (index + 1) % capacity;
    }

    if (table[index] == nullptr) {
        table[index] = new HashNode<const char*, int>(key, value);
        size++;

        if ((double)size / capacity >= 0.7) {
            resize();
        }
    }
    else {
        while (table[index] != nullptr)
        {
            if (table[index]->key == key && table[index]->value == value) { return; }
            index++;
            index = index % capacity;
        }
        table[index] = new HashNode<const char*, int>(key, value);
        size++;
    }
}

int HashTable::get(const char* key) {
    size_t index = HashFunction::Default(key, sizeof(key)) % capacity;

    while (table[index] != nullptr) {
        if (table[index]->key == key) {
            return table[index]->value;
        }
        index = (index + 1) % capacity;
    }

    return -1;  // Return -1 if the key is not found
}

void HashTable::print()
{
    for (int i = 0; i < capacity; i++)
    {
        if (table[i] != NULL)
        {
            std::cout << "Table position: " << i + 1 << "\nKey: " << table[i]->key << " Value: " << table[i]->value << std::endl << std::endl;
        }
    }
}

void HashTable::resize() {
    int newCapacity = capacity * 2;
    std::vector<HashNode<const char*, int>*> newTable(newCapacity, nullptr);

    for (int i = 0; i < capacity; ++i) {
        if (table[i] != nullptr) {
            size_t newIndex = HashFunction::Default(table[i]->key, sizeof(table[i]->key)) % newCapacity;
            while (newTable[newIndex] != nullptr) {
                newIndex = (newIndex + 1) % newCapacity;
            }
            newTable[newIndex] = table[i];
        }
    }

    table = std::move(newTable);
    capacity = newCapacity;
}

void HashTable::insertFile(const std::string& fileName) {
    std::ifstream fileStream(fileName, std::ios::binary | std::ios::ate);

    if (!fileStream.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::streamsize fileSize = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);

    std::string content(fileSize, '\0');
    if (fileStream.read(&content[0], fileSize)) {
        size_t hashValue = HashFunction::Default(fileName.c_str(), fileName.length()) % capacity;
        fileTable[hashValue] = new HashNode<std::string, std::string>(fileName, content);
        std::cout << "Inserted file: " << fileName << " with hash value: " << hashValue << std::endl;
    }
    else {
        std::cerr << "Failed to read file: " << fileName << std::endl;
    }
}

bool HashTable::getFile(const std::string& fileName, std::string& content) {
    size_t hashValue = HashFunction::Default(fileName.c_str(), fileName.length()) % capacity;

    if (fileTable[hashValue] != nullptr && table[hashValue]->key == fileName) {
        content = fileTable[hashValue]->value;
        return true;
    }

    return false;
}

void HashTable::printFile()
{
    for (int i = 0; i < capacity; i++)
    {
        if (fileTable[i] != nullptr)
        {
            std::cout << "\nFile " << i << ": " << fileTable[i]->key << std::endl << "~~Start File~~\n" << fileTable[i]->value << "\n~~End File~~\n";
        }
    }
}

