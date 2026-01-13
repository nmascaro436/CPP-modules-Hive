/**
 * Members of the Orthodox Canonical Form:
 * - Default constructor: initializes an object with default values during the object's instantiation
 * - Copy constructor: initializes a new object as a copy of an existing object
 * - Copy assignment operator: copies the content of one object to another object that already exists
 * - Destructor: called when an object goes out of scope or is deleted, used for cleaning up resources
 * 
 * Ad Hoc Polymorphism is a type of polymorphism where the same name (function or operator) can have
 * different implementations depending on the types of its arguments.The appropriate implementation
 * is selected by the compiler based on the argument types.
 * 
 * Fixed-point numbers are a way to represent decimal numbers using integers, where you reserve a fixed
 * number of bits for the fractional part. Similar to converting euros to cents but using powers of 2.
 * Most common one is 2^8 (256).
 * 
 */

#pragma once

#include <iostream>

class Fixed
{
	private:
	int _fixedPointNumber;
        static const int _fractionalBits = 8; // all the Fixed objects have this same value

	public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};
