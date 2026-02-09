#pragma once
#include <iostream>

class Bureaucrat
{
	private:
	const std::string name;
	int grade;

	public:
	Bureaucrat(std::string name, unsigned int grade);
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
	std::string getName() const;
	unsigned int getGrade() const;
	void incrementGrade();
	void decrementGrade();
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& cog);
