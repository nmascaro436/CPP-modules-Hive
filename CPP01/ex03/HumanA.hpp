#pragma once

#include <iostream>
#include "Weapon.hpp"
class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon; //Always has a weapon, a reference can never be null and must be initialized immediately

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack() const; // function doesn't modify the object
};
