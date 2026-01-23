#pragma once
#include <iostream>


/**
 * We can't create an object of an abstract class
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
