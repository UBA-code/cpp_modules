#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
		this->_grade = obj._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()
{
	return (this->_name);
}

int Bureaucrat::getGrade()
{
	return (this->_grade);
}

void Bureaucrat::inc()
{
	if (this->_grade <= 1)
		throw (GradeTooLowException());
	(this->_grade)--;
}

void Bureaucrat::dec()
{
	if (this->_grade >= 150)
		throw (GradeTooHighException());
	(this->_grade)++;
}

void Bureaucrat::checkGrade()
{
	if (this->_grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (this->_grade > 150)
		throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::signForm(Form& obj)
{
	try {
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << "\n";
	}
	catch (std::exception &err)
	{
		std::cerr << this->_name << " couldn’t sign " << obj.getName() << " because " << err.what();
	}
}

std::ostream& operator<<(std::ostream &out, Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n";
	return (out);
}
