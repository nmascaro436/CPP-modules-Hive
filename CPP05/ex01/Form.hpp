#pragma once
#include <iostream>

class Form
{
	private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

	public:
	Form();
	Form(std::string name, bool isSigned, int gradeS, int gradeE);
	Form(const Form& other);
	Form &operator=(const Form& other);
	~Form();
	class GradeTooHighException: public std::exception
	{
		public:
		const char* what() const noexcept override;
	};
	class GradeTooLowException: public std::exception
	{
		public:
		const char* what() const noexcept override;
	};
	const std::string
};
