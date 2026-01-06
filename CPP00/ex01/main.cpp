/**
 * Possibly i will need to use these:
 * -std::string name and then name.empty() (returns true or false depending if its empty or not)
 * -std::string text = "Hello World"; size_t pos = text.find("World");  // returns 6 (position where "World" starts)
 * -  std::cout << std::setw(10); std::cout << 77 << std::endl; // number of chars to be used as field width
*/
#include "PhoneBook.hpp"

int main()
{
	std::string word;
	PhoneBook phonebook;

	std::cout << "Welcome to the PhoneBook." << std::endl;
	while (true)
	{ 
		std::cout << "Please enter one of the following: ADD, SEARCH, EXIT." << std::endl;
		std::getline(std::cin, word);
		if (word == "ADD")
			phonebook.addContact();
		else if (word == "SEARCH")
			phonebook.displayContact();
		else if (word == "EXIT")
			break;
	}
}
