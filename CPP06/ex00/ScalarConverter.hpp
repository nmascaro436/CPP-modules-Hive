#pragma once
#include <iostream>

/**
 * TYPES OF CASTS
 * -Static cast: most used type, used to convert a value from one type to another, as long as
 * they're compatible (ex. numeric types or pointer in the same inheritance hierarchy).
 * -Dynamic cast: used to convert a pointer or reference to a base class to a pointer or reference
 * to a derived class, and checks at runtime the validity of the conversion, if it's not possible
 * it returns null pointer or null reference.
 * -Const cast: used to remove or add the constness of an object, it can be used to cast away the
 * constness of a value, allowing us to modify a const object.
 * -Reinterpret cast: used to convert the pointer to any other type of pointer, doesn't
 * perform any check whether the pointer converted is of the same type or not. Should be used
 * with caution, it can lead to undefined behavior.
 */

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter &operator=(const ScalarConverter& other);
	~ScalarConverter();
	
	public:
	static void convert(std::string literal);
};