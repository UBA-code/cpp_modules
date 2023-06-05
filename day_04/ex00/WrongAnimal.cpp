#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal copy constructor called\n";
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal copy Assigment operator called\n";
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destrutor called\n";
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << this->type << " Is Silence\n";
}
