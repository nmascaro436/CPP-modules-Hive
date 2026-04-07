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