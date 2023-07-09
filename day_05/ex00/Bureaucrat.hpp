#pragma once
#include "iostream"

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
				const char* what() const throw(){return ("Grade Too High\n");};
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(){return ("Grade Too Low\n");};
		};
};

std::ostream& operator<<(std::ostream &out, Bureaucrat& obj);