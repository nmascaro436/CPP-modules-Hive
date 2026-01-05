// an OBJECT is a collection of ATTRIBUTES (characteristics of the thing) and METHODS (actions 
// to perform) -> to create it we use a CLASS
// a member in a class can be defined as PUBLIC (can be accessed and modified outside the class) or 
// PRIVATE (can't be accessed or viewed outside the class)
// CONSTRUCTOR is a special METHOD that is automatically called when an OBJECT is instantiated
// (useful for assigning values to attributes as arguments), it has the same name as the CLASS
//
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact contacts[8];

	public:
	void add_contact();
	void display_contact();
	void exit_book();
};
