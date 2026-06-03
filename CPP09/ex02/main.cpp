#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: not enough parameters\n";
		return 1;
	}
	
	PmergeMe nums;
	nums.parseInput(argc, argv);
	nums.printBefore();
	nums.vectorSort();
	nums.dequeSort();

	return 0;
}