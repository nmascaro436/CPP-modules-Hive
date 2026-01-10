#include "Harl.hpp"

/**
 * Pointers to member functions let's us avoid if/else  conditions.
 * They store the address of a method that belongs to a class.
 * In this case we:
 * - Create an array of strings
 * - Create an array of function pointers: void (function returns nothing), Harl::*(pointer to
 * 	a Harl member function), functions[4] (array of four pointers), () function takes no parameters
 *  - If we find a matching level, we call that specific function (->* is an operator used for calling
 *   member function through a pointer)
 */

void Harl::complain(std::string level)
{
	std::string names[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	
	void (Harl::*functions[4])() = { 
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if(names[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "Unknown level. Valid levels: DEBUG, INFO, WARNING, ERROR\n";
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< "I've been coming for years, whereas you started working here just last month."
		<< std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
