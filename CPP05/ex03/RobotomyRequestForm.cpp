#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target(""){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
	{
        AForm::operator=(other);
		_target = other._target;
	}
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeE())
		throw GradeTooLowException();
	std::cout << "brrrrr grrrrrrr whirrrrr \n";
	if (rand() % 2 == 0)
		std::cout << _target << " has been successfully robotomized! :) \n";
	else
		std::cout << _target << " failed to be robotomized! :( \n";
}
