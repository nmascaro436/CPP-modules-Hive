#pragma once
#include <iostream>
#include <cstdint> // for uintptr_t (unsigned int which holds any pointer value)
#include "Data.hpp"

/**
 * Pointer and int are unrelated types, that's why we use the reinterpret_cast, bits stay
 * identical.
 */

class Serializer
{
	private:
	Serializer();
	Serializer(const Serializer& other);
	Serializer &operator=(const Serializer& other);
	~Serializer();

	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
