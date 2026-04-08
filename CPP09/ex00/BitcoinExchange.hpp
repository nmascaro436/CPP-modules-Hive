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
	std::string trimInput(const std::string& str);
	bool validateValue(const std::string& value);
	bool validateDate(const std::string& date);
	void lookUpDate(const std::string& date, double value);

	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange &operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void putDataInMap(const std::string& dataFile);
	void processInputFile(const std::string& inputFile);

}; 