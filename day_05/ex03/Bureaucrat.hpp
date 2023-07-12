#pragma once
#include "iostream"
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();
		std::string	getName() const;
		int			getGrade() const;
		void		inc();
		void		dec();
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw(){return ("Bureaucrat Grade Too High\n");};
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(){return ("Bureaucrat Grade Too Low\n");};
		};
		void		checkGrade();
		void		signForm(AForm& obj);
		void		executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat& obj);