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
	clock_t start = clock();
	FordJohnson(_vec);
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000000; // convert clock ticks to microseconds
	printAfter();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << time << " us\n";
}

void PmergeMe::dequeSort()
{
	clock_t start = clock();
	FordJohnson(_deq);
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000000; // convert clock ticks to microseconds
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << time << " us\n";
}

void PmergeMe::FordJohnson(std::vector<int>& vec)
{
	if (vec.size() <= 1) // already sorted and this is where recursion stops
		return ;
	std::vector<std::pair<int, int>> pairs; // std::pair holds two values together
	bool hasOddNum = vec.size() % 2 != 0; // remembers if we have a leftover element with no pair
	for (size_t i = 0; i + 1 < vec.size(); i += 2) // we make sure we don't go out of bounds and we advance two positions at a time
	{
		int winner = std::max(vec[i], vec[i + 1]); // picks larger
		int loser = std::min(vec[i], vec[i + 1]); // picks smaller
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
		mainChain.push_back(winners[i]); // add the sorted winners to the main chain

	std::vector<int> waitingToInsert;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first != winners[0]) // skip loser we already added
			waitingToInsert.push_back(pairs[i].second); // collection of losers that we need to add
	}

	std::vector<int> jacobsthal = getJacobsthal(waitingToInsert.size()); // gets the sequence for the size of numbers we need to add
	std::vector<bool> inserted(waitingToInsert.size(), false); //tracks which losers have been inserted

	for (size_t i = 2; i < jacobsthal.size(); i++)
	{
		int idx = jacobsthal[i] - 1; // jacobsthal numbers start counting at 1, so we substract 1 so its like the array (start at 0)
		if (idx < (int)waitingToInsert.size() && !inserted[idx]) // if index is valid and number isn't inserted yet
		{
			binaryInsert(mainChain, waitingToInsert[idx]); // insert
			inserted[idx] = true; // marks it as done
		}
		for (int j = idx - 1; j >= jacobsthal[i - 1] && j >= 0; j--) // fill everything between the current and previous Jacobsthal number
		{
			if (!inserted[j])
			{
				binaryInsert(mainChain, waitingToInsert[j]);
				inserted[j] = true;
			}
		}
	}
	for (size_t i = 0; i < waitingToInsert.size(); i++) // cleanup loop just in case jacobsthal missed, some numbers it can happen if waitingtoInsert is small
	{
    	if (!inserted[i])
        	binaryInsert(mainChain, waitingToInsert[i]);
	}

	if (hasOddNum)
		binaryInsert(mainChain, vec.back()); // insert the left out number
	vec = mainChain; // writes result back to original vector
}
void PmergeMe::FordJohnson(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return ;
	std::deque<std::pair<int, int>> pairs;
	bool hasOddNum = deq.size() % 2 != 0;
	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		int winner = std::max(deq[i], deq[i + 1]);
		int loser = std::min(deq[i], deq[i + 1]);
		pairs.push_back(std::make_pair(winner, loser));
	}

	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].first);
	}
	FordJohnson(winners);

	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == winners[0])
		{
			mainChain.push_back(pairs[i].second);
			break;
		}
	}
	for (size_t i = 0; i < winners.size(); i++)
		mainChain.push_back(winners[i]);

	std::deque<int> waitingToInsert;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first != winners[0])
			waitingToInsert.push_back(pairs[i].second);
	}

	std::vector<int> jacobsthal = getJacobsthal(waitingToInsert.size());
	std::vector<bool> inserted(waitingToInsert.size(), false);

	for (size_t i = 2; i < jacobsthal.size(); i++)
	{
		int idx = jacobsthal[i] - 1;
		if (idx < (int)waitingToInsert.size() && !inserted[idx])
		{
			binaryInsert(mainChain, waitingToInsert[idx]);
			inserted[idx] = true;
		}
		for (int j = idx - 1; j >= jacobsthal[i - 1] && j >= 0; j--)
		{
			if (!inserted[j])
			{
				binaryInsert(mainChain, waitingToInsert[j]);
				inserted[j] = true;
			}
		}
	}

	for (size_t i = 0; i < waitingToInsert.size(); i++)
	{
    	if (!inserted[i])
        	binaryInsert(mainChain, waitingToInsert[i]);
	}

	if (hasOddNum)
		binaryInsert(mainChain, deq.back());
	deq = mainChain;
}
void PmergeMe::binaryInsert(std::vector<int>& vec, int value)
{
	int left = 0; // starts beginning
	int right = vec.size() - 1; // end
	while (left <= right)
	{
		int mid = (left + right) / 2; // find middle position
		if (vec[mid] == value) // if there's a duplicate
		{
			left = mid; // left is set to where the duplicate is found and value is inserted there
			break;
		}
		else if (vec[mid] < value) // value we want to insert is bigger than middle number
			left = mid + 1; // num can't be on the left, so we move the range to be closer to the right side
		else
			right = mid - 1; // num can't be on the right, we move the range closer to the left
	}
	vec.insert(vec.begin() + left, value); // insert number in the vector
}
void PmergeMe::binaryInsert(std::deque<int>& deq, int value)
{
	int left = 0;
	int right = deq.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (deq[mid] == value)
		{
			left = mid;
			break;
		}
		else if (deq[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	deq.insert(deq.begin() + left, value);
}

std::vector<int> PmergeMe::getJacobsthal(int size)
{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0); // jacobsthal sequence starts with these
	jacobsthal.push_back(1);
	while (jacobsthal.back() < size) // keep generating numbers for the sequence until we exceed size we have
	{
		int n = jacobsthal.size();
		jacobsthal.push_back(jacobsthal[n - 1] + 2 * jacobsthal[n - 2]);
	}
	return jacobsthal;
}

void PmergeMe::printBefore()
{
	std::cout << "Before: " ;
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << '\n';
}

void PmergeMe::printAfter()
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << '\n';
}