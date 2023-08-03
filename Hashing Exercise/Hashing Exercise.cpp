#include <iostream>
#include "HashFunction.h"

int main()
{
    char test[] = "Gamer Time (Because I'm a gamer ;))";
    const char* Test = test;
    std::cout << "The char array: " << Test << std::endl << "Hash: " << HashFunction::Default(Test, strlen(Test));
}