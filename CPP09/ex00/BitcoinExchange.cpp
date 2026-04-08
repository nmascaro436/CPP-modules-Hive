#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): dateAndRate(other.dateAndRate) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) 
{
	if (this != &other)
		dateAndRate = other.dateAndRate;
	return *this;
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
	std::ifstream file(inputFile);
	if (!file)
	{
		std::cout << "Can't open input.txt file!\n";
		return;
	}
	std::string line;
	std::getline(file,line); //skips line of the header
	while (std::getline(file, line))
	{
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cout << "Error: bad input => " << line <<  '\n';
			continue;
		}
		std::string beforePipe = line.substr(0, pipe); // split
		std::string afterPipe = line.substr(pipe + 1);
		beforePipe = trimInput(beforePipe); //  trim
		afterPipe = trimInput(afterPipe);
		if (!validateDate(beforePipe))
			continue;
		if (!validateValue(afterPipe))
			continue;
		lookUpDate(beforePipe, std::stod(afterPipe));
	}
	file.close();
}

std::string BitcoinExchange::trimInput(const std::string& str)
{
	size_t start = str.find_first_not_of(" "); // finds first char that's not a space
	size_t end = str.find_last_not_of(" "); // finds last char that's not a space
	std::string trimmed = str.substr(start, end - start + 1); // get the actual string
	return trimmed;
}

bool BitcoinExchange::validateValue(const std::string& value)
{
	double number = 0;
	try
	{
		number = std::stod(value); //convert value to double 
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: bad input => " << value <<  '\n'; // if it fails
		return false;
	}
	if (number < 0 )
	{
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	if (number > 1000)
	{
		std::cout << "Error: too large a number.\n";
		return false;
	}
	return true;
}
bool BitcoinExchange::validateDate(const std::string& date)
{
	if (date.length() != 10)
	{
		std::cout << "Error: bad input => " << date <<  '\n';
		return false;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad input => " << date <<  '\n';
		return false;
	}
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	try
	{
		int y = std::stoi(year);
		int m = std::stoi(month);
		int d = std::stoi(day);
		if (m < 1 || m > 12)
		{
			std::cout << "Error: bad input => " << date <<  '\n';
			return false;
		}
		if (d < 1 || d > 31)
		{
			std::cout << "Error: bad input => " << date <<  '\n';
			return false;
		}
		if (y < 0)
		{
			std::cout << "Error: bad input => " << date <<  '\n';
			return false;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: bad input => " << date <<  '\n';
		return false;
	}
	return true;
}
void BitcoinExchange::lookUpDate(const std::string& date, double value)
{
	auto iterator = dateAndRate.upper_bound(date); //finds the first date in the map strictly greater than  input
	if (iterator == dateAndRate.begin()) //date is before every date
	{
		std::cout << "Error: date is already first\n";
		return;
	}
	iterator--; //gives closest date less than or equal to what we're looking for
	std::cout << date << " => "  <<  value << " = " << value * iterator->second << "\n";
}