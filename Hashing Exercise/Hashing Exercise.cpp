#include <iostream>
#include "HashFunction.h"

int main()
{
    char tmp[] = "abc";
    std::cout << "The char array: " << tmp << std::endl << "Hash: " << std::hex << HashFunction::Default(tmp, strlen(tmp)) << std::endl;
    tmp[0] = 'c';
    tmp[1] = 'b';
    tmp[2] = 'a';
    std::cout << "The char array: " << tmp << std::endl << "Hash: " << std::hex << HashFunction::Default(tmp, strlen(tmp)) << std::endl;
}