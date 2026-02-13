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

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	int requestedForm = -1;
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
			requestedForm = i;
	}
	switch(requestedForm)
	{
		case 0:
			std::cout << "Intern creates " << formName << '\n';
			return new ShrubberyCreationForm(formTarget);
		case 1:
			std::cout << "Intern creates " << formName << '\n';
			return new RobotomyRequestForm(formTarget);
		case 2:
			std::cout << "Intern creates " << formName << '\n';
			return new PresidentialPardonForm(formTarget);
		default: // no match case
			std::cout << "Intern couldn't create form, name doesn't exist! \n";
			return nullptr;
	}
}
