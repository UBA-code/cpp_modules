#include "Fixed.hpp"

// constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

// copy constructor
Fixed::Fixed(const Fixed &exist)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = exist;
}

// copy assigment operator, obj1 = obj2

Fixed &Fixed::operator=(const Fixed &exist)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &exist)
		this->fixedPoint = exist.getRawBits();
	return (*this);
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}
