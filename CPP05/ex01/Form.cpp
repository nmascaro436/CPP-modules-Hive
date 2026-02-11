#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){}

Form::Form(const std::string name, const int gradeS, const int gradeE): _name(name), _isSigned(false), _gradeToSign(gradeS), _gradeToExecute(gradeE)
{
	if (gradeS < 1 || gradeE < 1)
		throw GradeTooHighException();
	else if (gradeS > 150 || gradeE > 150)
		throw GradeTooLowException();
}

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

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _isSigned;
}

int Form::getGradeS() const
{
	return _gradeToSign;
}

int Form::getGradeE() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& user)
{
	if (user.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}
std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form named " << form.getName() << " , with signed status " << form.getSigned() << " has grade " << form.getGradeS()
	<< " required to sign it and grade " << form.getGradeE() << " required to execute it.";
    return out;
}
