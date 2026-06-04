#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

/**
 * Ford-Johnson algorithm:
 * - Pairs up numbers and compares each pair: get a "winner" (bigger num) and "loser" (smaller num)
 * 		from each pair
 * - Recursively sorts just the winners
 * - Inserts the losers back into the sorted winners using binary search (uses Jacobsthal numbers
 *  to minimize comparisons)
 * 
 * - Binary search always checks the middle of the already half sorted list to do less comparisons
 * - Jacobsthal numbers give an order that keeps the search range as small as possible for
 * 	each insertion
 * 
 * 
 * 
 * Vector stores elements contiguously in memory and has fast random access -> good for binary search
 * Deque stores elements in chunks and has fast insertion at front and back -> good for building main chain
 * 
 * 
 */

class PmergeMe
{
	private:
	std::vector<int> _vec;
	std::deque<int>  _deq;
	void FordJohnson(std::vector<int>& vec);
	void FordJohnson(std::deque<int>& deq);
	std::vector<int> getJacobsthal(int size);
	void binaryInsert(std::vector<int>& vec, int value);
	void binaryInsert(std::deque<int>& deq, int value);

	public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	void parseInput(int argc, char **argv);
	void vectorSort();
	void dequeSort();
	void printBefore();
	void printAfter();
};