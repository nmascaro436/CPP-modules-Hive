#pragma once
#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
	Intern();
	Intern(const Intern& other);
	Intern &operator=(const Intern& other);
	~Intern();
	AForm* makeform(const std::string& formName, const std::string& formTarget);
};
