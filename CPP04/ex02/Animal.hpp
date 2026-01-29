#pragma once
#include <iostream>


/**
 * An abstract class is a class that has at least one pure virtual function (when we assign
 * to 0).
 * We can't create an instance of an abstract base class, but we can create other
 * classes that are derived from it.
 */

class Animal
{
	protected:
	std::string type;

	public:
	Animal();
	Animal(const Animal& other);
	Animal &operator=(const Animal& other);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string getType() const;
};
