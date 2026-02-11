#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form form1("First one", 20, 10);
		std::cout << form1 << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Form form2("Second", -1, 151);
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat("Nuria", 20);
		
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	/*
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
	} */
	return 0;
}
