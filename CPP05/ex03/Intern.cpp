#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern& other) 
{
	(void)other;
	return *this;
}

Intern::~Intern(){}

AForm* Intern::makeform(const std::string& formName, const std::string& formTarget)
{
	if (formName != AForm.getName())
		std::cout << "Intern couldn't create form";
	else
		std::cout << "Intern creates " << formName;
}
