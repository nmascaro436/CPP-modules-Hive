#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_totalContacts = 0;
	_nextIndex = 0;
}
PhoneBook::~PhoneBook(){}

std::string PhoneBook::readRequiredField(std::string prompt)
{
	std::string input;

	while (true)
	{
		std::cout << VIOLET << prompt << RESET;
		if (!std::getline(std::cin, input)) // if ctrl + d
			return ""; 
		if (!input.empty() && input.find_first_not_of(" \t\n\r") != std::string::npos) // looks for the first char that is not a space char, if it returns npos means it was all spaces (it returns the first non space)
			return input;
		std::cout << RED << "Field can't be empty." << RESET << std::endl;
	}
}
void PhoneBook::addContact()
{
	Contact addedContact;
	std::string input;

	input = readRequiredField("First name: ");
	if (input.empty()) // ctrl + d
		return ;
	addedContact.setFirstName(input);
	input = readRequiredField("Last name: ");
	if (input.empty()) // ctrl + d
		return ;
	addedContact.setLastName(input);
	input = readRequiredField("Nickname: ");
	if (input.empty()) // ctrl + d
		return ;
	addedContact.setNickname(input);
	input = readRequiredField("Phone number: ");
	if (input.empty()) // ctrl + d
		return ;
	addedContact.setNum(input);
	input = readRequiredField("Darkest secret: ");
	if (input.empty()) // ctrl + d
		return ;
	addedContact.setSecret(input);

	_contacts[_nextIndex] = addedContact;
	std::cout << GREEN << "Contact successfully added at index " << RESET << _nextIndex << std::endl;
	if (_totalContacts < 8)
	{
		_totalContacts++;
	}
	_nextIndex++;
	if (_nextIndex == 8)
		_nextIndex = 0;
}

std::string PhoneBook::formatTable(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void PhoneBook::displayContact()
{
	int index = 0;
	if (_totalContacts == 0)
	{
		std::cout << RED << "Phonebook is empty. Please add some contacts." << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < _totalContacts; i++)
	{
		std::cout << std::setw(10) << i << '|'
				<< std::setw(10) << formatTable(_contacts[i].getFirstName()) << '|'
				<< std::setw(10) << formatTable(_contacts[i].getLastName()) << '|'
				<< std::setw(10) << formatTable(_contacts[i].getNickname())
				<< std::endl;
	}
	while (true)
	{
		std::cout << VIOLET << "Enter the index of the contact you want to see: " << RESET;
		std::cin >> index;
		if (std:: cin.eof()) // if someone does ctrl + d
		{
			std::cin.clear();
			return;
		} 
		if (std::cin.fail()) // just in case someone enters alphabetical chars
		{
			std::cout << RED << "Invalid index. Enter a number." << RESET << std::endl;
			std::cin.clear(); // clear error state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
			continue ;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear newline (throw away as many chars as needed but stop when you hit a newline)
		if (index < 0 || index >= _totalContacts)
		{
			std::cout << RED << "Invalid index. Try again." << RESET << std::endl;
			continue ;
		}
		break;
	}

	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getNum() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getSecret() << std::endl;
}


