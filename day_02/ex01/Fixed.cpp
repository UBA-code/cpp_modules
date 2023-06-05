#include "Fixed.hpp"

// constructor
Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
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
		this->fixedPoint = exist.fixedPoint;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
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

int getPower(int num, int power)
{
	int result = num;
	if (power == 0)
		return (1);
	if (power < 0)
		result = -result;
	for (int i = power; i > 1; i--)
		result *= num;
	return (result);
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = n << 8;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	float shifted = n * (float)getPower(2, this->fractionalBits);
	int fixed = (int)roundf(shifted);
	this->fixedPoint = fixed;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPoint / getPower(2, this->fractionalBits));
};

int Fixed::toInt(void) const
{
	return ((int)(this->fixedPoint) >> this->fractionalBits);
};
