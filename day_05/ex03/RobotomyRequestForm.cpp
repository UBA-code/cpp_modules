#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("Default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& obj)
: AForm(obj), _target(obj._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& obj)
{
	AForm::operator=(obj);
	this->_target = obj._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

AForm*	RobotomyRequestForm::clone()
{
	return (new RobotomyRequestForm(*this));
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (!this->getSigned())
		throw (AForm::notSigned());
	if (!(executor.getGrade() < this->getGradeExec()))
		throw (AForm::GradeTooLowException());
	static int i = 0;
	if (i % 2 == 0)
		std::cout << "BRAAAA " << this->_target << " has been robotomized\n";
	else
		std::cout << "the robotomy failed\n";
}