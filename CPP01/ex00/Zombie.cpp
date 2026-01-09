#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name) {} //creates the object with the name

Zombie::~Zombie(){
	std::cout << _name << "was destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << "BraiiiiiiinnnzzzZ..." << std::endl;
}

