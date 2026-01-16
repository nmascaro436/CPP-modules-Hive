#include "ClapTrap.hpp"

// Main that tests almost all the functionalities
int main()
{
	ClapTrap user1("Daisy");
	ClapTrap user2("Rose");
	ClapTrap user3("Tulip");

	user1.attack("Rose");
	user2.takeDamage(5);
	user3.attack("Rose");
	user2.takeDamage(5);
	user2.beRepaired(10);
	user3.takeDamage(20);
	user3.attack("Someone");
	return 0;
}
/*
// Main that displays more clearly that attack stops at 0 energy
int main()
{
	ClapTrap user1("Daisy");
	for (int i = 0; i < 12; i++)
	{
		user1.attack("Nobody");
	}
	return 0;
}
*/
/*
// Main to ensure no underflow (when the amount is bigger than the hit points)
int main ()
{
	ClapTrap user2("Rose");

	user2.takeDamage(5);
	user2.takeDamage(5); // HP = 0
	user2.takeDamage(5); // shouldn't change anything
	return 0;
}

*/
