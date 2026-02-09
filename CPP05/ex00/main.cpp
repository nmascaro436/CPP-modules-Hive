#include "Bureaucrat.hpp"

/**
 * Valid bureaucrat creation
Invalid bureaucrat creation (grade too high)
Invalid bureaucrat creation (grade too low)
Incrementing when it would go out of range
Decrementing when it would go out of range
Using the << operator to print bureaucrats
 */
int main()
{
	try
	{
		Bureaucrat user1("Nuria", 20);
		std::cout << user1 << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat user2("Jenni", -1);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat("Antti", 170);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat user3("Daniel", 1);
		user3.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat user4("Anton", 150);
		user4.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	return 0;
}