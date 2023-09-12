#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();
		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};
