#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
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

void Bureaucrat::signForm(AForm& obj)
{
	try {
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << "\n";
	}
	catch (std::string err)
	{
		std::cerr << this->_name << " couldn’t sign " << obj.getName() << " because " << err;
	}
}

std::ostream& operator<<(std::ostream &out, Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n";
	return (out);
}

void Bureaucrat::executeForm(AForm const & form)
{
	// std::string err = this->getName() + "";
	if (!form.getSigned() || !(this->getGrade() < form.getGradeExec()))
		throw((this->getName()) + " couldn't execute form\n");
}