#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "Frag Trap's constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
    std::cout << "Frag Trap's constructor called" << std::endl;
    return ;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "Frag Trap's copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "Frag Trap's destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap" << _name << "happily requests high-fives from others! :)" << std::endl;
}
