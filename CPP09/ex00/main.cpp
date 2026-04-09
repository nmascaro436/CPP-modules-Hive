#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file. Usage: ./btc input.txt\n";
		return 1;
	}

	BitcoinExchange data;

	data.putDataInMap("data.csv");
	data.processInputFile(argv[1]);
	return 0;
}

/**
 * 
2013-05-12 | 123abc       -> Error: bad input
2013-05-12 | abc           -> Error: bad input
2013-05-12 |               -> Error: bad input
 | 12                       -> Error: bad input
2013/05/12 | 12            -> Error: bad input
 2013-05-12 | 12           -> Valid, should pass (spaces trimmed)
2013-05-12 | 0             -> Valid, should pass
2013-05-12 | 1000          -> Valid, should pass
2013-05-12|1000.00          -> Valid decimal, should pass
2013-05-12 | +12            -> Valid, should pass (plus sign allowed)
2013-05-12 | 12.0.0         -> Error: bad input (malformed decimal)
 */