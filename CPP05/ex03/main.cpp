#include "Intern.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "------------- TESTS OF CREATION OF VALID FORM NAMES -------------\n ";
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat bureaucrat("Nuria", 1);
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Intern someOtherRandomIntern;
		AForm* scf;
		Bureaucrat bureaucrat2("Nuria", 1);
		scf = someOtherRandomIntern.makeForm("shrubbery creation", "Something");
		bureaucrat2.signForm(*scf);
		bureaucrat2.executeForm(*scf);
		delete scf;
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Intern evenSomeOtherRandomIntern;
		AForm* ppf;
		Bureaucrat bureaucrat3("Nuria", 1);
		ppf = evenSomeOtherRandomIntern.makeForm("presidential pardon", "Someone");
		bureaucrat3.signForm(*ppf);
		bureaucrat3.executeForm(*ppf);
		delete ppf;
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	
	std::cout << "------------- TESTS OF CREATION OF INVALID FORM NAMES -------------\n ";
	try
	{
		Intern someRandomIntern;
		AForm* wrongForm;
		wrongForm = someRandomIntern.makeForm("something wrong", "Bender");
		if (wrongForm)
			delete wrongForm;
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Intern someRandomIntern;
		AForm* anotherWrongForm;
		anotherWrongForm = someRandomIntern.makeForm("Shrubbery creation", "Something");
		if (anotherWrongForm)
			delete anotherWrongForm;
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	return 0;
}