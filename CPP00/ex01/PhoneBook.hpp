/**
 * An OBJECT is a collection of ATTRIBUTES (characteristics of the thing) and METHODS (actions
 * to perform) -> to create it we use a CLASS.
 * A member in a class can be defined as PUBLIC (can be accessed and modified outside the class) or
 * PRIVATE (can't be accessed or viewed outside the class).
 * CONSTRUCTOR is a special METHOD that is automatically called when an OBJECT is instantiated and
 * it has the same name as the CLASS.
 */

#pragma once // prevents multiple inclusion of the same header

#include <iomanip>
#include <limits>
#include "Contact.hpp"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define VIOLET     "\033[35m"
#define BLUE "\033[38;2;0;50;100m"
#define RESET      "\033[0m"

class PhoneBook
{
	private:
	Contact _contacts[8];
	int _totalContacts;
	int _nextIndex;
   	std::string readRequiredField(std::string prompt);
   	std::string formatTable(std::string str);
   
	public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void displayContact();
};
