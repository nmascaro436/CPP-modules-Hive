#include "Zombie.hpp"

int main ()
{
	Zombie* heapZombie = newZombie("Big zombie");
	heapZombie->announce();
	delete (heapZombie);
	randomChump("Mini zombie");
	return 0;
}