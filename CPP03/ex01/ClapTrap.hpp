#pragma once
# include <iostream>

class ClapTrap
{
    protected: // so the inheritance works correctly
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

    public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap &operator=(const ClapTrap &other);
    virtual ~ClapTrap(); // virtual to make sure ScavTrap's destructor isn't skipped, so no memory leaks occur
    virtual void attack(const std::string& target); // virtual because the ScavTrap class uses this function differently, so we want the compiler to look at the object type at runtime
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};
