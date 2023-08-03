#include "HashFunction.h"
namespace HashFunction {
	// implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length) {
		unsigned int hash = 0;
		for (unsigned int i = 0; i < length; ++i)
			hash += data[i];
		return hash;
	}
	// Implementation of a different hash function
	unsigned int newHash(const char* data, unsigned int length) {
		unsigned int hash = 0;
		for (unsigned int i = 0; i <= length; ++i)
		{
			hash += data[i] * data[i] + 69;
		}
		hash += hash % length;
		return hash;
	}
}