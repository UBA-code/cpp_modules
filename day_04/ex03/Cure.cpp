#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure default constructor called\n";
}

Cure::Cure(const std::string& type) : AMateria("cure")
{
	(void)type;
	// std::cout << "Cure constructor called\n";
}

Cure::Cure(const Cure& obj)
{
	// std::cout << "Cure copy constructor called\n";
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
	// std::cout << "Cure copy assigment operator called\n";
	AMateria::operator=(obj);
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called\n";
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
