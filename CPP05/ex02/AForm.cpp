#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){}

AForm::AForm(const std::string name, const int gradeS, const int gradeE): _name(name), _isSigned(false), _gradeToSign(gradeS), _gradeToExecute(gradeE)
{
	if (gradeS < 1 || gradeE < 1)
		throw GradeTooHighException();
	else if (gradeS > 150 || gradeE > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

AForm &AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form isn't signed!";
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _isSigned;
}

int AForm::getGradeS() const
{
	return _gradeToSign;
}

int AForm::getGradeE() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& user)
{
	if (user.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}
std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form named " << form.getName() << ", with signed status " << form.getSigned() << " has grade " << form.getGradeS()
	<< " required to sign it and grade " << form.getGradeE() << " required to execute it.";
    return out;
}

