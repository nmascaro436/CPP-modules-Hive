#include "Span.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "SUBJECT TESTS\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << "EXTRA TESTS\n";
	std::cout << "--------- Test with too many elements with addNumber ---------\n";
	try
	{
		sp.addNumber(20); // should throw maximum capacity
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "--------- Test with not enough elements ---------\n";
	Span sp1 = Span(10);
	try
	{
		sp1.addNumber(1);
		sp1.shortestSpan(); // should throw not enough numbers stored
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "--------- Test with 10,000 numbers ---------\n";
	Span bigSp = Span(10000);
	std::vector<int> bigContainer;
	for (size_t i = 0; i < 10000; i++)
		bigContainer.push_back(rand());
	try
	{
		bigSp.addMultipleNumbers(bigContainer.begin(), bigContainer.end()); // should successfully add 10000 numbers
		std::cout << bigSp.shortestSpan() << std::endl;
		std::cout << bigSp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "--------- Test with too many elements with addMultipleNumbers ---------\n";
	Span sp3 = Span(60);
	std::vector<int> smallContainer;
	for (size_t i = 0; i < 70; i++)
		smallContainer.push_back(rand());
	try
	{
		sp3.addMultipleNumbers(smallContainer.begin(), smallContainer.end()); // should throw maximum capacity reached
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}