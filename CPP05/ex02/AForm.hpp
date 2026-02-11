#pragma once
#include <iostream>

class Bureaucrat;
class AForm
{
	private:
	const std::string _name;
	bool _isSigned; // we shouldn't pass it as a parameter because it's not a value required to define the object, we set it to true or false after construction
	const int _gradeToSign;
	const int _gradeToExecute;

	public:
	AForm();
	AForm(const std::string name, const int gradeS, const int gradeE);
	AForm(const AForm& other);
	AForm &operator=(const AForm& other);
	virtual ~AForm();
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
	class FormNotSignedException: public std::exception
	{
		public:
		const char* what() const noexcept override;
	};
	const std::string& getName() const;
	bool getSigned() const;
	int getGradeS() const;
	int getGradeE() const;
	void beSigned(const Bureaucrat& user);
	virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream& operator<<(std::ostream& out, const AForm& form);
