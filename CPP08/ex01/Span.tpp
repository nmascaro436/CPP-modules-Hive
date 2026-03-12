#include "Span.hpp"

Span::Span(unsigned int N): maxCapacity(N) {}

void Span::addNumber(int add)
{
	if (numbers.size() == maxCapacity)
		throw std::runtime_error("Maximum capacity reached");
	numbers.push_back(add); // appending to the end of the vector
}
int Span::shortestSpan()
{
	if (numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers stored");

	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end()); //because then the closest pair will always be next to each other
	int minimum = sorted[1] - sorted[0]; //first pair's difference so we can then compare
	for (size_t i = 1; i < sorted.size(); i++)
	{
		if (sorted[i] - sorted[i -1] < minimum)
			minimum = sorted[i] - sorted[i -1]; //difference between each adjacent pair
	}
	return minimum;
}
int Span::longestSpan()
{
	if (numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers stored");
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	int maximum = sorted[sorted.size() - 1] - sorted[0]; // last minus first
	return maximum;
}
template<typename iterator>
void Span::addMultipleNumbers(iterator start, iterator end)
{
	if (std::distance(start, end) + numbers.size() > maxCapacity) // range trying to add + numbers already there
		throw std::runtime_error("Maximum capacity reached");
	for (iterator it = start; it != end; it++)
		addNumber(*it);
}