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