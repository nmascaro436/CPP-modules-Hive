#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): //initialize members e.g. member1(initial_value), member2(initial_value)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &other): //initialize members e.g. member1(other.member1), member2(other.member2) 
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    // e.g., member1 = other.member1;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

