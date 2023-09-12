#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& obj)
: AForm(obj), _target(obj._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& obj)
{
	AForm::operator=(obj);
	this->_target = obj._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget() const{
	return (this->_target);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw (AForm::notSigned());
	if (!(executor.getGrade() < this->getGradeExec()))
		throw (AForm::GradeTooLowException());
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out.is_open())
	{
		std::cerr << "failed open create file\n";
		return ;
	}
	out << "                                                         .\n\
                                              .         ;  \n\
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%  %;   \n\
                    :         ;                   :;%;'     .,   \n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'   \n\
                        `@%.  `;@%.      ;@@%;         \n\
                          `@%%. `@%%    ;@@%;        \n\
                            ;@%. :@%%  %@@%;       \n\
                              %@bd%%%bd%%:;     \n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '         \n\
                                %@@@o%;:(.,'         \n\
                            `.. %@@@o%::;         \n\
                               `)@@@o%::;         \n\
                                %@@(o)::;        \n\
                               .%@@@@%::;         \n\
                               ;%@@@@%::;.          \n\
                              ;%@@@@%%:;;;. \n\
                          ...;%@@@@@%%:;;;;,..    UBA\n\
";
}