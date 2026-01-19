#include "ScavTrap.hpp"

int main()
{
	ClapTrap user1("First");
	ScavTrap user2("Second");
	ScavTrap user3("Third");

	user1.attack("Someone");
	user1.attack("Second");
	user1.takeDamage(5);

	user3.attack("Someone");
	user2.guardGate();

	user3.beRepaired(10);

	for (int i = 0; i < 11; i++)
		user3.takeDamage(10);
	user3.attack("Someone");
	
	return 0;
}
