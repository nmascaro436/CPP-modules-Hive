#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	srand(time(NULL)); // allows rand() to produce different results every time I run the program
	std::cout << "--------------------- SHRUBBERY CREATION FORM TESTS ---------------- \n";
	try
	{
		ShrubberyCreationForm shrubbery("beach"); // should sign and execute successfully
		Bureaucrat user1("Nuria", 130);
		user1.signForm(shrubbery);
		user1.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		ShrubberyCreationForm shrubbery("house"); // should throw form not signed exception
		Bureaucrat user2("Marta", 130);
		user2.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		ShrubberyCreationForm shrubbery("desert"); // should throw grade too low exception
		Bureaucrat user3("Enric", 130);
		Bureaucrat user4("Joan", 150);
		user3.signForm(shrubbery);
		user4.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	std::cout << "--------------------- ROBOTOMY REQUEST FORM TESTS ---------------- \n";
	try
	{
		RobotomyRequestForm robotomy("Bella"); // should sign and execute successfully (execution success is random though)
		Bureaucrat user5("Lina", 40);
		user5.signForm(robotomy);
		user5.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		RobotomyRequestForm robotomy("Ariel"); // should throw form not signed exception
		Bureaucrat user6("Anna", 40);
		user6.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		RobotomyRequestForm robotomy("Aurora"); // should throw grade too low exception
		Bureaucrat user7("Mar", 40);
		Bureaucrat user8("Oscar", 46);
		user7.signForm(robotomy);
		user8.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	std::cout << "--------------------- PRESIDENTIAL PARDON FORM TESTS ---------------- \n";
	try
	{
		PresidentialPardonForm presidential("Flower"); // should sign and execute successfully
		Bureaucrat user9("Angie", 2);
		user9.signForm(presidential);
		user9.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		PresidentialPardonForm presidential("Thor"); // should throw form not signed exception
		Bureaucrat user10("Bernat", 20);
		user10.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		PresidentialPardonForm presidential("Alberta"); // should throw grade too low exception
		Bureaucrat user10("David", 20);
		Bureaucrat user11("Carme", 6);
		user10.signForm(presidential);
		user11.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	return 0;
}