#pragma once
#include <iostream>
#include <fstream>
#include <map>

/**
 * Map stores values in pairs and it keeps them automatically sorted
 */

class BitcoinExchange
{
	private:
	std::map<std::string, double> dateAndRate;

	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange &operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void putDataInMap(const std::string& dataFile);
	void processInputFile(const std::string& inputFile);

}; 