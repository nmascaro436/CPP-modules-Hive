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
	std::cout << std::fixed << std::setprecision(1); // forces decimal notation and showing 1 digit after decimal point
	if (literal == "-inff" || literal == "-inf") // negative infinity
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
	else if (literal == "+inff" || literal == "+inf") // positive infinity
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else if (literal == "nanf" || literal == "nan") // not a number (invalid or undefined mathematical result)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		if (!std::isprint(literal[0]))
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: " << "'" << literal[0] << "'" << '\n';
		std::cout << "int: " << static_cast<int>(literal[0]) << '\n';
		std::cout << "float: " << static_cast<float>(literal[0]) << "f\n";
		std::cout << "double: " << static_cast<double>(literal[0]) << '\n';
	}
	else if (literal[literal.length() - 1] == 'f')
	{
		int fCount = 0;
		for (size_t i = 0; i < literal.length(); i++)
			if (literal[i] == 'f')
				fCount++;
		if (fCount > 1) //if it has more than 1 f it's invalid number
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			return;
		}
		try
		{
			float fl = std::stof(literal);
			if (!std::isprint(static_cast<unsigned char>(fl)) || fl > 127 || fl < 0) //isprint expects a positive number so we guarantee it's never negative
				std::cout << "char: Non displayable\n";
			else
				std::cout << "char: " << "'" << static_cast<char>(fl) << "'" << '\n';
			if (static_cast<double>(fl) > INT_MAX || static_cast<double>(fl) < INT_MIN) //float can't store the INT_MAX, cast to double toget precision
				std::cout << "int: impossible\n";
			else
				std::cout << "int: " << static_cast<int>(fl) << '\n';
			std::cout << "float: " << fl << "f\n";
			std::cout << "double: " << static_cast<double>(fl) << '\n';
		}
		catch(const std::exception& e)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
		}
	}
	else if (literal.find(".") != std::string::npos)
	{
		int dotCount = 0;
		for (size_t i = 0; i < literal.length(); i++)
			if (literal[i] == '.')
				dotCount++;
		if (dotCount > 1) //if it has more than 1 . it's invalid number
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			return;
		}
		try
		{
			double db = std::stod(literal);
			if (!std::isprint(static_cast<unsigned char>(db)) || db > 127 || db < 0)
				std::cout << "char: Non displayable\n";
			else
				std::cout << "char: " << "'" << static_cast<char>(db) << "'" << '\n';
			if (db > INT_MAX || db < INT_MIN)
				std::cout << "int: impossible\n";
			else
				std::cout << "int: " << static_cast<int>(db) << '\n';
			if (db > FLT_MAX || db < -FLT_MAX) // double holds much larger values than float, so we check if it fits
				std::cout << "float: impossible\n";
			else
				std::cout << "float: " << static_cast<float>(db) << "f\n";
			std::cout << "double: " << static_cast<double>(db) << '\n';
		}
		catch(const std::exception& e)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
		}
	}
	else
	{
		try
		{
			long num = std::stol(literal);
			if (!std::isprint(static_cast<unsigned char>(num)) || num > 127 || num < 0)
				std::cout << "char: Non displayable\n";
			else
				std::cout << "char: " << "'" << static_cast<char>(num) << "'" << '\n';
			if (num > INT_MAX || num < INT_MIN)
				std::cout << "int: impossible\n";
			else
				std::cout << "int: " << static_cast<int>(num) << '\n';
			std::cout << "float: " << static_cast<float>(num) << "f\n";
			std::cout << "double: " << static_cast<double>(num) << '\n';
		}
		catch(const std::exception& e)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
		}
	}
}
