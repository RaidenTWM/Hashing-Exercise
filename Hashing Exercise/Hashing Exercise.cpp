#include <iostream>
#include "HashFunction.h"
#include "HashTable.h"
#include <chrono>
#include <thread>


int main()
{
    HashTable tempTable;
    bool exit = false;
    bool choice = false;
    std::string filename;
    while (!exit)
    {
        std::cout << "Do you want to run the example program?\n(1)Yes or (0)No: ";
        std::cin >> choice;
        if (choice)
        {
            tempTable.insert("Raiden", 468471895);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            tempTable.insert("Thomas", 0);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            tempTable.insert("Jimbo", 911);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            tempTable.insert("Destructoride", 416574850);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            tempTable.insert("Raiden", 27);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            tempTable.insert("Raiden", 27);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            tempTable.insert("Raiden", -47);
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            tempTable.print();
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            filename = "Example.bin";
            tempTable.insertFile(filename);
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            filename = "Example2.bin";
            tempTable.insertFile(filename);
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
        else
        {
            choice = true;
            while (choice)
            {
                std::cout << "Please enter the full filename. (example: file.bin)\n";
                std::cin >> filename;
                tempTable.insertFile(filename);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::cout << "Do you want to insert another file?\n(1)Yes or (0)No: ";
                std::cin >> choice;
            }
        }
        tempTable.printFile();
        std::cout << "Do you want to quit the program?\n(1)Yes or (0)No: ";
        std::cin >> exit;
        system("cls");
    }
}