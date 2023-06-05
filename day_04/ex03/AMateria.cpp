#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
	// std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(std::string const& type) : type(type)
{
	// std::cout << "AMateria constructor called\n";
}

AMateria::AMateria(const AMateria& obj)
{
	// std::cout << "AMateria copy constructor called\n";
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	// std::cout << "AMateria copy constructor called\n";
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called\n";
}

std::string const& AMateria::getType(void) const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
