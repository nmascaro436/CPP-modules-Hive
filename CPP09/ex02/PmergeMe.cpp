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

}

void PmergeMe::dequeSort()
{

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