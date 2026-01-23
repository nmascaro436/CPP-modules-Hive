#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}
Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i]; // copy each of the elements individually
	std::cout << "Brain copy constructor called" << std::endl;
}
Brain &Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}    
    return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
