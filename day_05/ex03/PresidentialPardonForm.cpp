#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("Default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& obj)
: AForm(obj), _target(obj._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& obj)
{
	AForm::operator=(obj);
	obj._target = obj._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

AForm*	PresidentialPardonForm::clone()
{
	return (new PresidentialPardonForm(*this));
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (!this->getSigned())
		throw (AForm::notSigned());
	if (!(executor.getGrade() < this->getGradeExec()))
		throw (AForm::GradeTooLowException());
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
}