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
				throw std::runtime_error("Error");
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
	bool hasOddNum = (vec.size() % 2 != 0); // remembers if we have a leftover element with no pair
	for (size_t i = 0; i + 1 < vec.size(); i += 2) // we make sure we don't go out of bounds and we advance two positions at a time
	{
		if (vec[i] > vec[i + 1]) // make pairs and put bigger number first
			pairs.push_back(std::make_pair(vec[i], vec[i +1])); 
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].first); // add only the winners 
	}

	FordJohnson(winners); // recursively sort the winners

	std::vector<std::pair<int, int>> sortedPairs; //rebuild pairs in the new sorted winner order
	for (size_t i = 0; i < winners.size(); i++) // iterate sorted winners
	{
		for (size_t j = 0; j < pairs.size(); j++) // search in pairs
		{
			if (pairs[j].first == winners[i]) // found a match
			{
				sortedPairs.push_back(pairs[j]); // save it
				pairs.erase(pairs.begin() + j); // remove the pair we just used to handle duplicates, so the match doesn't happen on the same pair
				break; // move on to the next winner
			}
		}
	}
	
	std::vector<int> mainChain;

    mainChain.push_back(sortedPairs[0].second); // push loser of smallest winner

    for (size_t i = 0; i < winners.size(); i++)
	{
        mainChain.push_back(winners[i]); // add the sorted winners to the main chain
	}
	
	std::vector<int> waitingToInsert;
	for (size_t i = 1; i < sortedPairs.size(); i++)
		waitingToInsert.push_back(sortedPairs[i].second); // collection of losers that we need to add
	
	std::vector<int> order = getJacobsthal(waitingToInsert.size()); // insert them in optimal order to minimize comparisons
	for (size_t i = 0; i < order.size(); i++)
    {
        binaryInsert(mainChain, waitingToInsert[order[i]]);
    }

	if (hasOddNum)
		binaryInsert(mainChain, vec.back()); // insert the left out number
	vec = mainChain; // writes result back to original vector
}

void PmergeMe::FordJohnson(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return;
	
	std::deque<std::pair<int, int>> pairs;
	bool hasOddNum = (deq.size() % 2 != 0);
	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i +1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}

	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].first); 
	}

	FordJohnson(winners);

	std::deque<std::pair<int, int>> sortedPairs;
	for (size_t i = 0; i < winners.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == winners[i])
			{
				sortedPairs.push_back(pairs[j]);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}

	std::deque<int> mainChain;

    mainChain.push_back(sortedPairs[0].second);

    for (size_t i = 0; i < winners.size(); i++)
	{
        mainChain.push_back(winners[i]);
	}
	
	std::deque<int> waitingToInsert;
	for (size_t i = 1; i < sortedPairs.size(); i++)
		waitingToInsert.push_back(sortedPairs[i].second);
	
	std::vector<int> order = getJacobsthal(waitingToInsert.size());
	for (size_t i = 0; i < order.size(); i++)
    {
        binaryInsert(mainChain, waitingToInsert[order[i]]);
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

std::vector<int> PmergeMe::getJacobsthal(int size) // returns sequence of indices telling order to insert the losers, minimizes the comparisons
{
	std::vector<int> order;

	if (size == 0) // no losers to insert
    	return order; // return empty

    std::vector<int> jac;
    jac.push_back(0); // first numbers of jacobsthal sequence
    jac.push_back(1);

    while (jac.back() < size) // constructs the rest of the sequence until the last on is at least "size"
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

    std::vector<bool> used(size, false); // track which indices were used

    order.push_back(0); // always start with index 0, Ford-Johnson always inserts the first loser first
    used[0] = true;

    for (size_t i = 3; i < jac.size(); i++) // skip first 3 values, they're kinda like base case to build the sequence, not useful in this case
    {
        int upper = std::min(jac[i], size); // current jacobsthal number
        int lower = jac[i - 1]; // previous number

        for (int j = upper; j > lower; j--) // go backwards in each block from the sequence
        {
            int index = j - 1; // convert to index

            if (index < size && !used[index])
            {
                order.push_back(index); //add number
                used[index] = true; // mark as done
            }
        }
    }
    for (int i = 0; i < size; i++) // safety loop just in case some indices were forgotten
    {
        if (!used[i])
            order.push_back(i);
    }
    return order;
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