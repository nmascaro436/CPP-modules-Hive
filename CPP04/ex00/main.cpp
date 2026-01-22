#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	//Destructors
	delete (j);
	delete (i);
	delete (meta);


	std::cout << "-----More tests, with WrongCat and WrongAnimal------" << std::endl;
	const Animal* normalDog = new Dog();
	const Animal* normalCat = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	std::cout << normalDog->getType() << " " << std::endl;
	std::cout << normalCat->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	normalDog->makeSound();
	normalCat->makeSound();
	wrong->makeSound();

	//Destructors
	delete (normalDog);
	delete (normalCat);
	delete (wrong);

	return 0;
}
