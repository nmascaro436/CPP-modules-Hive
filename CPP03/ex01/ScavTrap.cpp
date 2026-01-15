#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): //initialize members e.g. member1(initial_value), member2(initial_value)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap &other): //initialize members e.g. member1(other.member1), member2(other.member2) 
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    // e.g., member1 = other.member1;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

