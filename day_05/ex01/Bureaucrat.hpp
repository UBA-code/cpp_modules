#pragma once
#include "iostream"
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();
		std::string	getName();
		int			getGrade();
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
		void		signForm(Form& obj);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat& obj);