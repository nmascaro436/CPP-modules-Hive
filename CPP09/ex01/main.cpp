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

/**
 * Valid tests:
 *   "8 9 * 9 - 9 - 9 - 4 - 1 +" → 42
 *   "7 7 * 7 -" → 42
 * 	 "1 2 * 2 / 2 * 2 4 - +" → 0
 *   "9 3 /" → 3
 *   "1 9 -" → -8
 *   "5 5 * 2 +" → 27
 *   "0 0 +" → 0
 * 
 * Invalid:
 * 	"(1 + 1)" → Error
 *  "1 2 a +" → Error
 *  "1 2 ++" → Error 
 *  "1 2 -+" → Error
 *  "1 2 + +" → Error
 * 	"+ 1 2" → Error
 *  "1 +" → Error
 *  "1 2" → Error
 *  "1 2 3 +" → Error
 * 	"5 0 /" → Error
 */