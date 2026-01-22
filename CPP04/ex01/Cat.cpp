#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& other): Animal(other)
{
	brain = new Brain(*other.brain); // creates a deep copy of Brain, new brain (dereferences the pointer to get the Brain object), so each object has its own Brain
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat &Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
	    Animal::operator=(other);
		delete brain; // free the old brain
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound() const
{
	std::cout << "Animal named " << type << " goes meow meow" << std::endl;
}
