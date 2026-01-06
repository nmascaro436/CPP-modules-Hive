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
	int index = 0;
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
	std::cout << "Enter the index of the contact you want to see: " << std::endl;
	std::cin >> index;
	if (std::cin.fail()) // just in case someone enters alphabetical chars
	{
		std::cout << "Invalid index. Enter a number." << std::endl;
		std::cin.clear(); // clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear newline (throw away as many chars as needed but stop when you hit a newline)
	if (index < 0 || index > _totalContacts - 1)
	{
		std::cout << "Invalid index. Try again." << std::endl;
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


