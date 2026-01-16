#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), 
_attackDamage(0)
{
    std::cout << "ClapTrap's default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hitPoints(other._hitPoints),
_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap's copy constructor called" << std::endl;
    return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap's copy assignment operator called" << std::endl;
    if (this != &other)
	{
    	this->_name = other._name;
    	this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
    	this->_attackDamage = other._attackDamage;
	}
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap's destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack! It has no hit points or "
		"energy points left."  << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
	<< _attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead! Can't take damage!" << std::endl;
		return;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints = _hitPoints - amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage! It now has "
	<< _hitPoints << " hit points left." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired anymore :(! It has no hit "
		"points or energy points left." << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints = _hitPoints + amount;
	std::cout << "ClapTrap " << _name << " repairs itself, for "
	<< amount << " points and now has " << _hitPoints << " hit points!" << std::endl;
}
