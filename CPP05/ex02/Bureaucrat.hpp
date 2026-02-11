#pragma once
#include <iostream>
#include "Form.hpp"
class Bureaucrat
{
	private:
	const std::string _name;
	int _grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat &operator=(const Bureaucrat& other);
	~Bureaucrat();
	class GradeTooHighException: public std::exception
	{
		public:
		const char* what() const noexcept override; //provides a readable description of the exception
	};
	class GradeTooLowException: public std::exception
	{
		public:
		const char* what() const noexcept override;
	};
	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form);
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& cog);
