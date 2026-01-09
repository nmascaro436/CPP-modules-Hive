// when i press ctr+d something weird happens!!! need to fix
// after it says field can't be empty it goes back to the please enter one of the followiing, but i
// want it to go back to the same field and same when it says invalid index
// it accepts anything for first name last name nickname and phone number, like even numbers when it doesnt make sense or letters in phone number\

#include "PhoneBook.hpp"

int main()
{
	std::string word;
	PhoneBook phonebook;

	std::cout << BLUE;
    std::cout << "====================================\n";  
    std::cout << RESET;
	std::cout << BLUE << "Welcome to the PhoneBook." << RESET << std::endl;
    std::cout << BLUE;
    std::cout << "====================================\n";
    std::cout << RESET;
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
