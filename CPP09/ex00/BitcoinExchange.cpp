#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) 
{

}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::putDataInMap(const std::string& dataFile)
{
	std::ifstream file(dataFile);
	if (!file)
	{
		std::cout << "Can't open data.csv file!\n";
		return;
	}
	std::string line;
	std::getline(file,line); //skips line of the header
	while (std::getline(file, line))
	{
		size_t comma = line.find(',');
		std::string beforeComma = line.substr(0, comma);
		std::string afterComma = line.substr(comma + 1);
		dateAndRate[beforeComma] = std::stod(afterComma); 
	}
	file.close();
}
void  BitcoinExchange::processInputFile(const std::string& inputFile)
{

}
