#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(std::string type) : WrongAnimal("WrongCat")
{
	(void)type;
	std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << "WrongCat copy constructor called\n";
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "WrongCat copy assigment operator called\n";
	WrongAnimal::operator=(obj);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << this->type << " Say 'MEOW MEOW'\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}
