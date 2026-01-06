// an OBJECT is a collection of ATTRIBUTES (characteristics of the thing) and METHODS (actions 
// to perform) -> to create it we use a CLASS
// a member in a class can be defined as PUBLIC (can be accessed and modified outside the class) or 
// PRIVATE (can't be accessed or viewed outside the class)
// CONSTRUCTOR is a special METHOD that is automatically called when an OBJECT is instantiated
// (useful for assigning values to attributes as arguments), it has the same name as the CLASS
//
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#pragma once // prevents multiple inclusion of the same header

#include <iomanip>
#include <limits>
#include "Contact.hpp"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define VIOLET     "\033[35m"
#define BLUE "\033[38;2;173;216;230m"
#define RESET      "\033[0m"
//std::cout << RED << "Red text from file1!" << RESET << "\n";
/**
 *  std::cout << BLUE;
    std::cout << "====================================\n";  
    std::cout << RESET;

    std::cout << VIOLET;
    std::cout << "  ____ ___  _    _ ____  _       \n";
    std::cout << " / ___| _ \\| |  | |  _ \\| |_ ___ \n";
    std::cout << "| |  _|  _/| |  | | |_) |   _|_ |\n";
    std::cout << "|_| |_||_|  |_|  |_|____/ \\__|_| \n";
    std::cout << RESET;

    std::cout << BLUE;
    std::cout << "====================================\n";
    std::cout << RESET;
 */

class PhoneBook
{
	private:
	Contact _contacts[8];
	unsigned int _totalContacts;
	int _nextIndex;

	public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void displayContact();
};

#endif