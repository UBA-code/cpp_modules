#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor);
		AForm*	clone();
};