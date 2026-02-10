#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150) {} // picking some default values because the Bureaucrat always has to have a name and grade

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		grade = other.grade; // we dont assign the name because it's const, so it's immutable
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

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}
void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}
std::ostream& operator<<(std::ostream& out, const Bureaucrat& cog)
{
    out << cog.getName() <<", bureaucrat grade " << cog.getGrade();
    return out;
}
