#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	total_contacts = 0;
	next_index = 0;
}

int PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string	nickname;
	std::string num;
	std::string secret;

	std::cout << "Enter your first name." << std::endl;
	std::cin >> first_name;
	std::cout << "Enter your last name." << std::endl;
	std::cin >> last_name;
	std::cout << "Enter your nickname." << std::endl;
	std::cin >> nickname;
	std::cout << "Enter your phone number." << std::endl;
	std::cin >> num;
	std::cout << "Enter your darkest secret." << std::endl;
	std::cin >> secret;
	if (first_name == "" || last_name == "" || nickname  == "" || num == "" || secret == "")
	{
		std::cout << "Field can't be empty." << std::endl; // maybe use std::getline???
		return 1;
	}
	Contact contact_info(first_name, last_name, nickname, num, secret);
	contacts[next_index] = contact_info;
	if (total_contacts < 8)
	{
		total_contacts++;
	}
	next_index++;
	if (next_index == 8)
		next_index = 0;
	return 0;
}

std::string format_table(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void PhoneBook::display_contact()
{
	for (int i = 0; i < total_contacts; i++)
	{
		std::cout << std::setw(10) << i << '|'
				<< std::setw(10) << format_table(contacts[i].get_first_name()) << '|'
				<< std::setw(10) << format_table(contacts[i].get_last_name()) << '|'
				<< std::setw(10) << format_table(contacts[i].get_nickname())
				<< std::endl;
	}
}
// prompt user again for the index of the entry to display, if it's wrong throw some error and return,
// otherwise display contact information 1 line = 1 field

