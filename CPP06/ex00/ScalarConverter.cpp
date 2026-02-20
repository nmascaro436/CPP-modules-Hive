#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
	std::cout << std::fixed << std::setprecision(1);
	if (literal == "-inff" || literal == "-inf") // negative infinity
	{
		std::cout << "Char: impossible.\n";
		std::cout << "Int: impossible.\n";
		std::cout << "Float: -inff.\n";
		std::cout << "Double: -inf.\n";
	}
	else if (literal == "+inff" || literal == "+inf") // positive infinity
	{
		std::cout << "Char: impossible.\n";
		std::cout << "Int: impossible.\n";
		std::cout << "Float: +inff.\n";
		std::cout << "Double: +inf.\n";
	}
	else if (literal == "nanf" || literal == "nan") // not a number (invalid or undefined mathematical result)
	{
		std::cout << "Char: impossible.\n";
		std::cout << "Int: impossible.\n";
		std::cout << "Float: nanf.\n";
		std::cout << "Double: nan.\n";
	}
	else if (literal[0] == '\'')
	{
		if (!std::isprint(literal[1]))
			std::cout << "Char: non displayable.\n";
		else
			std::cout << "Char: " << literal[1] << '\n';
		std::cout << "Int: " << static_cast<int>(literal[1]) << '\n';
		std::cout << "Float: " << static_cast<float>(literal[1]) << "f\n";
		std::cout << "Double: " << static_cast<double>(literal[1]) << '\n';
	}
	else if (literal[literal.length() - 1] == 'f')
	{ 
		try
		{
			float fl = std::stof(literal);
			if (!std::isprint(static_cast<unsigned char>(fl)) || fl > 127 || fl < 0) //!!!
				std::cout << "Char: non displayable.\n";
			else
				std::cout << "Char: " << static_cast<char>(fl) << '\n';
			long check = std::stol(literal); //!!!
			if (check > INT_MAX || check < INT_MIN)
				std::cout << "Int: impossible.\n";
			else
				std::cout << "Int: " << static_cast<int>(check) << '\n';
			if (fl > FLT_MAX || fl < -FLT_MAX) //!!!
				std::cout << "Float: impossible.\n";
			else
				std::cout << "Float: " << fl << "f\n";
			std::cout << "Double: " << static_cast<double>(fl) << '\n';
		}
		catch(const std::exception& e)
		{
			std::cout << "Char: impossible.\n";
			std::cout << "Int: impossible.\n";
			std::cout << "Float: impossible.\n";
			std::cout << "Double: impossible.\n";
		}
	}
	else if (literal.find(".") != std::string::npos)
	{
		try
		{
			double db = std::stod(literal);
			if (!std::isprint(static_cast<unsigned char>(db)) || db > 127 || db < 0)
				std::cout << "Char: non displayable.\n";
			else
				std::cout << "Char: " << static_cast<char>(db) << '\n';
			long check = std::stol(literal);
			if (check > INT_MAX || check < INT_MIN)
				std::cout << "Int: impossible.\n";
			else
				std::cout << "Int: " << static_cast<int>(db) << '\n';
			if (db > FLT_MAX || db < -FLT_MAX)
				std::cout << "Float: impossible.\n";
			else
				std::cout << "Float: " << static_cast<float>(db) << "f\n";
			std::cout << "Double: " << static_cast<double>(db) << '\n';
		}
		catch(const std::exception& e)
		{
			std::cout << "Char: impossible.\n";
			std::cout << "Int: impossible.\n";
			std::cout << "Float: impossible.\n";
			std::cout << "Double: impossible.\n";
		}
	}
	else
	{
		try
		{
			long num = std::stoi(literal);
			if (!std::isprint(static_cast<unsigned char>(num)) || num > 127 || num < 0)
				std::cout << "Char: non displayable.\n";
			else
				std::cout << "Char: " << static_cast<char>(num) << '\n';
			if (num > INT_MAX || num < INT_MIN)
				std::cout << "Int: impossible.\n";
			else
				std::cout << "Int: " << static_cast<int>(num) << '\n';
			std::cout << "Float: " << static_cast<float>(num) << "f\n";
			std::cout << "Double: " << static_cast<double>(num) << '\n';
		}
		catch(const std::exception& e)
		{
			std::cout << "Char: impossible.\n";
			std::cout << "Int: impossible.\n";
			std::cout << "Float: impossible.\n";
			std::cout << "Double: impossible.\n";
		}
	}
}
