#include "Bureaucrat.hpp"

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
		Bureaucrat user3("Antti", 170);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat user4("Daniel", 1);
		user4.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat user5("Anton", 150);
		user5.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	return 0;
}
