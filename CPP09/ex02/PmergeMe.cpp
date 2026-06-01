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
	if (vec.size() <= 1) // already sorted
		return ;
	std::vector<std::pair<int, int>> pairs; // std::pair holds two values together
	bool hasOddNum = vec.size() % 2 != 0;
	for (size_t i = 0; i + 1 < vec.size(); i += 2) // we make sure we don't go out of bounds and we advance two positions at a time
	{
		int winner = std::max(vec[i], vec[i + 1]);
		int loser = std::min(vec[i], vec[i + 1]);
		pairs.push_back(std::make_pair(winner, loser));
	}

	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].first); // add only the winners 
	}
	FordJohnson(winners); // recursively sort the winners until we have 1 number left

	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == winners[0]) // find loser paired with the smallest winner
		{
			mainChain.push_back(pairs[i].second); // put it at the front
			break;
		}
	}
	for (size_t i = 0; i < winners.size(); i++)
		mainChain.push_back(winners[i]);

	std::vector<int> waitingToInsert;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first != winners[0]) // skip loser we already added
			waitingToInsert.push_back(pairs[i].second);
	}
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

std::vector<int> PmergeMe::getJacobsthal(int size)
{
	
}