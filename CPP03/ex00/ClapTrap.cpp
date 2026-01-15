#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), 
_attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hitPoints(other._hitPoints),
_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hit points, its health was suffering"
		" and it died. Can't attack :(" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points. Can't attack :("
		<< std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
	<< _attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" 
	<< std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't repair!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points to repair!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself, getting "
	<< amount << " hit points!" << std::endl;
}
