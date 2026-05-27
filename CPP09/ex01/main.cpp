#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: not enough parameters.";
		return 1;
	}
	RPN op;

	op.processOperation(argv[1]);

	return 0;
}