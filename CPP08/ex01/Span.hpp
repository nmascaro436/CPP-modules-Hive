#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

//vector represents a dynamic array capable of resizing automatically, stores elements in contiguous memory locations

class Span
{
	private:
	std::vector<int> numbers;
	unsigned int maxCapacity;

	public:
	Span(unsigned int N);
	void addNumber(int add);
	int shortestSpan();
	int longestSpan();
	template<typename iterator>
	void addMultipleNumbers(iterator start, iterator end);
};

#include "Span.tpp"