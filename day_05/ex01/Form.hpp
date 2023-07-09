#pragma once
#include "Bureaucrat.hpp"

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
		void		checkGrade();
		std::string	getName();
		bool	getSigned();
		int		getGradeExec();
		int		getGradeSign();
};
