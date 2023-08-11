#pragma once
#include <functional>
#include <iostream>
namespace HashFunction {
	typedef std::function< unsigned int(const char*, unsigned int)> HashFunc;
	unsigned int newHash(const char* data, unsigned int length);
	// a helper to access a default hash function
	static HashFunc Default = newHash;
}