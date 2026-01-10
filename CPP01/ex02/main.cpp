/**
 * A reference works as an alias for an existing variable, providing an alternative name
 * for it and referring to the same memory. It´s not like a pointer that has its own memory
 * and its like a new variable. A POINTER POINTS TO AN OBJECT A REFERENCE IS THE OBJECT!
 */

#include <iostream>

int main ()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Memory address of str: " << &str << std::endl;
	std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;

	return 0;
}
