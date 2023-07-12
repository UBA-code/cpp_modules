#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(PresidentialPardonForm& obj);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor);
};