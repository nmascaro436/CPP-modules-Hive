/**
 * Members of the Orthodox Canonical Form:
 * - Default constructor: initializes an object with default values during the object's instantiation
 * - Copy constructor: initializes a new object as a copy of an existing object
 * - Copy assignment operator: copies the content of one object to another object that already exists
 * - Destructor: called when an object goes out of scope or is deleted, used for cleaning up resources
 * 
 * Operator overloading is basically defining what operators like +, =, - do with the custom classes
 */

#pragma once

#include <iostream>

class Fixed
{
	private:
		
	public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
};
