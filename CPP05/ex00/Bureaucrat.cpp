#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {} // picking some default values because the Bureaucrat always has to have a name and grade

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = other._grade; // we dont assign the name because it's const, so it's immutable
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade is too low!";
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}
std::ostream& operator<<(std::ostream& out, const Bureaucrat& cog)
{
    out << cog.getName() <<", bureaucrat grade " << cog.getGrade();
    return out;
}
