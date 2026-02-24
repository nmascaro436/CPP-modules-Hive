#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments. Usage example: ./convert 'c'\n";
		return -1;
	}
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}

/**
 * Test cases ./convert:
 * - a Normal behaviour
 * - z Normal behaviour
 * - -42 Char non displayable, others normal 
 * - 127 Char non displayable, others normal 
 * - 2147483648 Char non displayable, int impossible, others normal 
 * - -2147483648 Char non displayable, others normal 
 * - 0.0f Char non displayable, others normal 
 * - 4.2f Char non displayable, others normal 
 * - -4.2f Char non displayable, others normal 
 * - 0.0 Char non displayable, others normal 
 * - hello Everything impossible
 * - 1.2.3 Everything impossible
 * - 4ff Everything impossible
 */