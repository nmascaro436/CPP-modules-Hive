#pragma once
# include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();

        virtual void attack(const std::string& target) override; //override used to explicitly indicate that the function is intended to override a base class function
        void guardGate();
};

