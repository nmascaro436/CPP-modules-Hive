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

	std::cout << "First name: " << std::endl;
	std::getline(std::cin, firstName);
	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, num);
	std::cout << "Darkest secret: " << std::endl;
	std::getline(std::cin, secret);

	if (firstName.empty() || lastName.empty() || nickname.empty()|| num.empty() || secret.empty())
	{
		std::cout << "Field can't be empty." << std::endl;
		return ;
	}
	addedContact.setFirstName (firstName);
	addedContact.setLastName (lastName);
	addedContact.setNickname (nickname);
	addedContact.setNum (num);
	addedContact.setSecret (secret);
	_contacts[_nextIndex] = addedContact;
	std::cout << "Contact successfully added at index " << _nextIndex << std::endl;
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
	if (_totalContacts == 0)
	{
		std::cout << "Phonebook is empty. Please add some contacts." << std::endl;
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
}
// prompt user again for the index of the entry to display, if it's wrong throw some error and return,
// otherwise display contact information 1 line = 1 field

