#include "Form.hpp"

Form::Form()
: _name("Default"), _signed(0), _gradeExec(1), _gradeSign(1){}

Form::Form(std::string name, int gradeSign, int gradeExec)
	: _name(name), _signed(0), _gradeExec(gradeExec), _gradeSign(gradeSign)
{
	this->checkGrade();
}

Form::Form(Form& obj)
: _name(obj._name), _signed(0), _gradeExec(obj._gradeExec), _gradeSign(obj._gradeSign)
{
	this->checkGrade();
}

Form& Form::operator=(Form& obj)
{
	if (this != &obj)
		this->_signed = obj._signed;
	this->checkGrade();
	return (*this);
}

void Form::checkGrade()
{
	if (this->_gradeExec > 150 || this->_gradeSign > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (this->_gradeExec < 1 || this->_gradeSign < 1)
		throw(Bureaucrat::GradeTooHighException());
}

std::string Form::getName()
{
	return (this->_name);
}

bool Form::getSigned()
{
	return (this->_signed);
}

int Form::getGradeExec()
{
	return (this->_gradeExec);
}

int Form::getGradeSign()
{
	return (this->_gradeSign);
}