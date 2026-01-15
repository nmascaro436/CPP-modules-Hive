#pragma once
# include <iostream>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(const ClapTrap& other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
};

