#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;

	std::cout << "-----Array of animals: little farm-----" << std::endl;

	Animal* farm[10];
	for (int i = 0; i < 5; i++)
		farm[i] = new Dog();
	for (int i = 5; i < 10; i++)
		farm[i] = new Cat();
	for (int i = 0; i < 10; i++)
		farm[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete farm[i];

	return 0;
}
