// when i press ctr+d something weird happens!!! need to fix
#include "PhoneBook.hpp"

int main()
{
	std::string word;
	PhoneBook phonebook;

	std::cout << "Welcome to the PhoneBook." << std::endl;
	while (true)
	{ 
		std::cout << "Please enter one of the following (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, word);
		if (word == "ADD")
			phonebook.addContact();
		else if (word == "SEARCH")
			phonebook.displayContact();
		else if (word == "EXIT")
			break;
	}
}
