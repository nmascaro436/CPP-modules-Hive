#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other): operation(other.operation) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		operation = other.operation;
	return *this;
}

RPN::~RPN() {}

void RPN::processOperation(const std::string& str)
{
	std::istringstream iss(str); // reads a string word by word (detects spaces)
	std::string token;
	while (iss >> token)
	{
		if (token.length() == 1 && isdigit(token[0])) // if token is number
			operation.push(std::stoi(token)); // convert to int and add to stack
		else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) 
		{
			if (operation.size() < 2) // need at least 2 numbers in the stack
			{
				std::cerr << "Error: not enough numbers\n";
				return;
			}
			int firstNum = operation.top(); operation.pop();
			int secondNum = operation.top(); operation.pop();
			if (token[0] == '+')
				operation.push(firstNum + secondNum);
			else if (token[0] == '-')
				operation.push(secondNum - firstNum);
			else if (token[0] == '*')
				operation.push(firstNum * secondNum);
			else
			{
				if (firstNum == 0)
				{
					std::cerr << "Error: division by zero\n";
					return;
				}
				operation.push(secondNum / firstNum);
			}
		}
		else
		{
			std::cerr << "Error\n";
			return;
		}
	}

	if (operation.size() != 1) // if after the loop the stack has more than 1 number its invalid
	{
		std::cerr << "Error\n";
		return;
	}
	std::cout << operation.top() << "\n";
}