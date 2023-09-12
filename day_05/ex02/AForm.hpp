#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeExec;
		const int			_gradeSign;
	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(AForm& obj);
		AForm& operator=(AForm& obj);
		virtual ~AForm() = 0;
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw(){return ("Form Grade Too High\n");};
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(){return ("Form Grade Too Low\n");};
		};
		class notSigned : public std::exception {
			public:
				const char* what() const throw(){return ("Form Not Signed\n");};
		};
		void			checkGrade();
		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeExec() const;
		int				getGradeSign() const;
		void			beSigned(Bureaucrat& obj);
		virtual void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, AForm& o);