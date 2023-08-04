#pragma once
#include "HashFunction.h"
template<typename KeyType, typename T>
class HashTable
{
public:
	HashTable(unsigned int size) : m_size(size), m_data(new T[size]) {}
	~HashTable() { delete[] m_data; }

	T& operator [] (const KeyType& key)
	{
		auto hashedKey = hash(key) % m_size;
		return m_data[hashedkey];
	}
private:
	T* m_data;
	unsigned int m_size;
	template<typename A, typename B>
	struct Pair {
		A first;
		B second;
	};
};

