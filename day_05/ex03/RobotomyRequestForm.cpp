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
	if (!this->getSigned() || !(executor.getGrade() < this->getGradeExec()))
		throw ("the robotomy failed\n");
	std::cout << this->getName() << " MAKE TOOOOOOOO MUCH NOISES !!!!!!!!!!\n";
	std::cout << this->_target << " has been robotomized \
	successfully 50% of the tim\n";
}