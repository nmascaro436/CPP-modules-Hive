// when i press ctr+d something weird happens!!! need to fix



#include "PhoneBook.hpp"

int main()
{
	std::string word;
	PhoneBook phonebook;

	std::cout << BLUE;
    std::cout << "====================================\n";  
    std::cout << RESET;
	std::cout << BLUE << "Welcome to your awesome PhoneBook." << RESET << std::endl;
    std::cout << BLUE;
    std::cout << "====================================\n";
    std::cout << RESET;
	while (true)
	{ 
		std::cout << "Please enter one of the following (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, word)) // if ctrl + d
			break;
		if (word == "ADD")
			phonebook.addContact();
		else if (word == "SEARCH")
			phonebook.displayContact();
		else if (word == "EXIT")
			break;
	}
}
