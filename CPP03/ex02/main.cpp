#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap user1("First");
	ScavTrap user2("Second");
	FragTrap user3("Third");

	user1.attack("Some user");
	user2.attack("Some other guy");
	user3.attack("Someone");

	user1.takeDamage(5);
	user2.takeDamage(50);
	user3.takeDamage(90);

	user2.guardGate();
	user3.highFivesGuys();

	user3.beRepaired(10);

	return 0;
}
