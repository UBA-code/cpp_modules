#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice default constructor called\n";
}

Ice::Ice(const std::string& type) : AMateria("ice")
{
	(void)type;
	// std::cout << "Ice constructor called\n";
}

Ice::Ice(const Ice& obj)
{
	// std::cout << "Ice copy constructor called\n";
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
	// std::cout << "Ice copy assigment operator called\n";
	AMateria::operator=(obj);
	return (*this);
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called\n";
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*\n";
}
