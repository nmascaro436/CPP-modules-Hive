#ifndef HUMANB_HPP
#define HUMANB_HPP

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon; // can start unarmed and set it later

	public:
		HumanB(std::string name);
		~HumanB();
		void attack() const;
		void setWeapon(Weapon& weapon);
};


#endif