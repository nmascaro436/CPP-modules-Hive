#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie* creature = new Zombie(name); // allocates memory
	return (creature);
}
