#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeExec;
		const int			_gradeSign;
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(Form& obj);
		Form& operator=(Form& obj);
		~Form();
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw(){return ("Form Grade Too High\n");};
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(){return ("Form Grade Too Low\n");};
		};
		void		checkGrade();
		std::string	getName();
		bool		getSigned();
		int			getGradeExec();
		int			getGradeSign();
		void		beSigned(Bureaucrat& obj);
};

std::ostream& operator<<(std::ostream& out, Form& o);