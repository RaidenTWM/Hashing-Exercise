#include "HashFunction.h"
namespace HashFunction {
	// Implementation of a different hash function
	unsigned int newHash(const char* data, unsigned int length) {
		unsigned int hash = 0;
		for (unsigned int i = 0; i <= length; ++i)
		{
			hash = (hash << 5) - hash + data[i] * data[i]; 
			hash &= 0xFFFFFFFF; //Masking 32 Bits
		}
		return hash;
	}
}