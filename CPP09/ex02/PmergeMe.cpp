#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other): _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string numStr(argv[i]); 
		for (size_t idx = 0; idx < numStr.length(); idx++) // check each char of number
		{
			if (!isdigit(numStr[idx]))
			{
				std::cerr << "Error\n";
				return;
			}
		}
		int num = std::stoi(numStr);
		_vec.push_back(num);
		_deq.push_back(num);
	}
}

void PmergeMe::vectorSort()
{
	std::cout << "Before: " ;
	for (int i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << '\n';
	
	clock_t start = clock();
	FordJohnson(_vec);
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000000; // convert clock ticks to microseconds
	std::cout << "After: ";
	for (int i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << '\n';
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << time << " us\n";
}

void PmergeMe::dequeSort()
{
	std::cout << "Before: " ;
	for (int i = 0; i < _deq.size(); i++)
	{
		std::cout << _deq[i] << " ";
	}
	std::cout << '\n';
	
	clock_t start = clock();
	FordJohnson(_deq);
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000000; // convert clock ticks to microseconds
	std::cout << "After: ";
	for (int i = 0; i < _deq.size(); i++)
	{
		std::cout << _deq[i] << " ";
	}
	std::cout << '\n';
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << time << " us\n";
}

void PmergeMe::FordJohnson(std::vector<int>& vec)
{

}
void PmergeMe::FordJohnson(std::deque<int>& deq)
{

}
void PmergeMe::binaryInsert(std::vector<int>& vec, int value)
{

}
void PmergeMe::binaryInsert(std::deque<int>& deq, int value)
{

}