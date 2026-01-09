#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_totalContacts = 0;
	_nextIndex = 0;
}
PhoneBook::~PhoneBook(){}

void PhoneBook::addContact()
{
	std::string firstName, lastName, nickname, num, secret;
	Contact addedContact;

	std::cout << VIOLET << "First name: " << RESET;
	std::getline(std::cin, firstName);
	std::cout << VIOLET << "Last name: " << RESET;
	std::getline(std::cin, lastName);
	std::cout << VIOLET << "Nickname: " << RESET;
	std::getline(std::cin, nickname);
	std::cout << VIOLET << "Phone number: " << RESET;
	std::getline(std::cin, num);
	std::cout << VIOLET << "Darkest secret: " << RESET;
	std::getline(std::cin, secret);

	if (firstName.empty() || lastName.empty() || nickname.empty()|| num.empty() || secret.empty())
	{
		std::cout << RED << "Field can't be empty." << RESET << std::endl;
		return ;
	}
	addedContact.setFirstName (firstName);
	addedContact.setLastName (lastName);
	addedContact.setNickname (nickname);
	addedContact.setNum (num);
	addedContact.setSecret (secret);
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

std::string formatTable(std::string str)
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
	std::cout << VIOLET << "Enter the index of the contact you want to see: " << RESET;
	std::cin >> index;
	if (std::cin.fail()) // just in case someone enters alphabetical chars
	{
		std::cout << RED << "Invalid index. Enter a number:" << RESET;
		std::cin.clear(); // clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear newline (throw away as many chars as needed but stop when you hit a newline)
	if (index < 0 || index > _totalContacts - 1)
	{
		std::cout << RED << "Invalid index. Try again." << RESET << std::endl;
		return ;
	}
	else
	{
		std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << _contacts[index].getNum() << std::endl;
		std::cout << "Darkest secret: " << _contacts[index].getSecret() << std::endl;
	}
}


