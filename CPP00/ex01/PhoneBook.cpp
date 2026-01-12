#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_totalContacts = 0;
	_nextIndex = 0;
}
PhoneBook::~PhoneBook(){}

/**
 * Ensures that the value entered is never empty.
 * Loops until valid input is received. Reads a line of input, if EOF (ctrl + D),
 * it returns an empty string.
 * If input is not empty and is not all whitespace (function searches for the first char that
 * is not a space), the input is valid so it returns.
 */
std::string PhoneBook::readRequiredField(std::string prompt)
{
	std::string input;

	while (true)
	{
		std::cout << VIOLET << prompt << RESET;
		if (!std::getline(std::cin, input))
			return "";
		if (!input.empty() && input.find_first_not_of(" \t\n\r") != std::string::npos)
			return input;
		std::cout << RED << "Field can't be empty." << RESET << std::endl;
	}
}
void PhoneBook::addContact()
{
	Contact addedContact;
	std::string input;

	input = readRequiredField("First name: ");
	if (input.empty())
		return ;
	addedContact.setFirstName(input);
	input = readRequiredField("Last name: ");
	if (input.empty())
		return ;
	addedContact.setLastName(input);
	input = readRequiredField("Nickname: ");
	if (input.empty())
		return ;
	addedContact.setNickname(input);
	input = readRequiredField("Phone number: ");
	if (input.empty())
		return ;
	addedContact.setNum(input);
	input = readRequiredField("Darkest secret: ");
	if (input.empty())
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
		if (std::cin.eof()) // if ctrl + d
		{
			std::cin.clear();
			return ;
		} 
		if (std::cin.fail()) // if alphabetical chars are entered, fail because cin expects an int
		{
			std::cout << RED << "Invalid index. Enter a number." << RESET << std::endl;
			std::cin.clear(); // clear error state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
			continue ;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear newline after valid input
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


