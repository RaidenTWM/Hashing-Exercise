#include <iostream>
#include "HashFunction.h"
#include "HashTable.h"

int main()
{
    HashTable tempTable;
    tempTable.insert("Raiden", 468471895);
    tempTable.insert("Thomas", 0);
    tempTable.insert("Jimbo", 911);
    tempTable.insert("Destructoride", 416574850);
    tempTable.print();
}