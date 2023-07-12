#include "AForm.hpp"

AForm::AForm()
: _name("Default"), _signed(0), _gradeExec(1), _gradeSign(1){}

AForm::AForm(std::string name, int gradeSign, int gradeExec)
	: _name(name), _signed(0), _gradeExec(gradeExec), _gradeSign(gradeSign)
{
	this->checkGrade();
}

AForm::AForm(AForm& obj)
: _name(obj._name), _signed(0), _gradeExec(obj._gradeExec), _gradeSign(obj._gradeSign)
{
	this->checkGrade();
}

AForm& AForm::operator=(AForm& obj)
{
	if (this != &obj)
		this->_signed = obj._signed;
	this->checkGrade();
	return (*this);
}

AForm::~AForm(){};
void AForm::checkGrade()
{
	if (this->_gradeExec > 150 || this->_gradeSign > 150)
		throw(AForm::GradeTooLowException());
	else if (this->_gradeExec < 1 || this->_gradeSign < 1)
		throw(AForm::GradeTooHighException());
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

int AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

void	AForm::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() <= this->getGradeSign())
		this->_signed = 1;
	else
		throw (obj.getName() + " grade low than " + this->_name + "\n");
}

std::ostream& operator<<(std::ostream& out, AForm& o)
{
	out << "Name: " << o.getName() << "\n";
	out << "is Signed ? " << (o.getSigned() ? "Yes" : "No") << "\n";
	out << "Grade Execution " << o.getGradeExec() << "\n";
	out << "Grade Sign " << o.getGradeSign() << "\n";
	return (out);
}
