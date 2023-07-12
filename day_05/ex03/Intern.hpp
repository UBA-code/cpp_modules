#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern& obj);
		Intern& operator=(Intern& obj);
		~Intern();
		AForm* makeForm(std::string name, std::string target);
		class unvalidName : public std::exception {
				const char* what() const throw(){return ("Name not valide\n");};
		};
};