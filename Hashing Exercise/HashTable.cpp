#include "HashTable.h"
#include "HashFunction.h"

HashTable::HashTable() {
    capacity = 8;
    size = 0;
    table.resize(capacity, nullptr);
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        delete table[i];
    }
}

void HashTable::insert(const char* key, int value) {
    size_t index = HashFunction::Default(key, sizeof(key)) % capacity;

    while (table[index] != nullptr && table[index]->key != key) {
        index = (index + 1) % capacity;
    }

    if (table[index] == nullptr) {
        table[index] = new HashNode(key, value);
        size++;

        if ((double)size / capacity >= 0.7) {
            resize();
        }
    }
    else {
        table[index]->value = value;
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
    std::vector<HashNode*> newTable(newCapacity, nullptr);

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