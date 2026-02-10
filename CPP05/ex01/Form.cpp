#include "Form.hpp"

Form::Form(): {}

Form::Form(std::string name, bool isSigned, int gradeS, int gradeE): _name(name), _isSigned(false), _gradeToSign(gradeS), _gradeToExecute(gradeE) {}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

Form &Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade is too low!";
}
