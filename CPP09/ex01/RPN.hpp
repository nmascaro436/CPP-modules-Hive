#pragma once
#include <iostream>
#include <sstream>
#include <stack>

/**
 * RPN reads left to right, when you see a number you save it and when you see an operator 
 * you use the last 2 saved numbers.
 * Stack is best option here because it naturally keeps track of the last 2 numbers: we push
 * numbers on top ad when we need 2 we just pop them off.
 */

class RPN
{
	private:
	std::stack<int> operation;
	
	public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();
	void processOperation(const std::string& str);
} ;