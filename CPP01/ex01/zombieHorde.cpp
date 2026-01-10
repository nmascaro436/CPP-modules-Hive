#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;
	
	Zombie* creatures = new Zombie[N];
	for (int i = 0; i < N; i++)
		creatures[i].setName(name);
	return creatures;
}