#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
class Form
{
	private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

	public:
	Form();
	Form(const std::string name, const int gradeS, const int gradeE);
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
	const std::string& getName() const;
	bool getSigned() const;
	int getGradeS() const;
	int getGradeE() const;
	void beSigned(const Bureaucrat& user);
	
};
std::ostream& operator<<(std::ostream& out, const Form& form);

