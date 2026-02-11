#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form form1("First one", 20, 10); // should construct successfully
		std::cout << form1 << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Form form2("Second", -1, 151); // should throw exception too high
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat user1("Nuria", 20); // should set status to 1 (signed)
		Form form3("Third", 50, 40);
		form3.beSigned(user1);
		std::cout << form3 << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat user2("Marta", 20); // should throw exception grade too low
		Form form4("Third", 10, 40);
		form4.beSigned(user2);

	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat user3("Nuria", 20); // should print successful message for signing
		Form form5("Third", 50, 40);
		user3.signForm(form5);

	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	try
	{
		Bureaucrat user4("Marta", 20); // should print unsuccessful message for signing
		Form form6("Third", 10, 40);
		user4.signForm(form6);

	}
	catch(const std::exception& e)
	{
		std::cout << "This is wrong! " << e.what() << '\n';
	}
	return 0;
}
