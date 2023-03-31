#include "Fixed.hpp"

// constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

// copy constructor
Fixed::Fixed(const Fixed& exist)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = exist;
	// this->fixedPoint = exist.fixedPoint;
}


//* operators implementetion

//? copy assigment operator, obj1 = obj2
Fixed& Fixed::operator=(const Fixed& exist)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &exist)
		this->fixedPoint = exist.fixedPoint;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << (float)obj.fixedPoint / getPower(2, 8);
    return os;
}

//? prefix
Fixed&	Fixed::operator++()
{
	++this->fixedPoint;
	return (*this);
}

//? postfix
Fixed	Fixed::operator++(int n)
{
	Fixed *old = new Fixed(*this);
	this->fixedPoint++;
	return (*old);
}

//? prefix
Fixed&	Fixed::operator--()
{
	Fixed *old = new Fixed(*this);
	this->fixedPoint++;
	return (*old);
}

//? postfix
Fixed	Fixed::operator--(int n)
{
	--this->fixedPoint;
	return (*this);
}


//! value of fixed-point number and not value
bool	Fixed::operator>(const Fixed& obj) const
{
	return (this->fixedPoint > obj.fixedPoint);
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return (this->fixedPoint < obj.fixedPoint);
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return (this->fixedPoint >= obj.fixedPoint);
}

bool	Fixed::operator<=(const Fixed& obj) const
{
	return (this->fixedPoint <= obj.fixedPoint);
}

bool	Fixed::operator==(const Fixed& obj) const
{
	return (this->fixedPoint == obj.fixedPoint);
}

bool	Fixed::operator!=(const Fixed& obj) const
{
	return (this->fixedPoint != obj.fixedPoint);
}

float	Fixed::operator+(const Fixed& obj) const
{
	return (this->fixedPoint + obj.fixedPoint);
}

float	Fixed::operator-(const Fixed& obj) const
{
	return (this->fixedPoint - obj.fixedPoint);
}

Fixed	Fixed::operator*(const Fixed& obj) const
{
	return (Fixed((float)(this->toFloat() * obj.toFloat())));
}

float	Fixed::operator/(const Fixed& obj) const
{
	return ((this->fixedPoint / obj.fixedPoint));
}


// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
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
	float	shifted = n * (float)getPower(2, this->fractionalBits);
	int		fixed = (int)roundf(shifted);
	this->fixedPoint = fixed;
}

float	Fixed::toFloat( void ) const{
	return ((float)this->fixedPoint / getPower(2, this->fractionalBits));
};

int		Fixed::toInt( void ) const{
	return ((int)(this->fixedPoint) >> this->fractionalBits); // we dicard the fractional bits
};

float Fixed::min(Fixed &fixed1, Fixed &fixed2) //! prototype need check
{
	return (fixed1.toFloat() < fixed2.toFloat() ? fixed1.toFloat() : fixed2.toFloat());
}

float Fixed::max(Fixed &fixed1, Fixed &fixed2) //! prototype need check
{
	return (fixed1.toFloat() > fixed2.toFloat() ? fixed1.toFloat() : fixed2.toFloat());
}

float Fixed::min(const Fixed &fixed1, const Fixed &fixed2) //! prototype need check
{
	return (fixed1.toFloat() < fixed2.toFloat() ? fixed1.toFloat() : fixed2.toFloat());
}

float Fixed::max(const Fixed &fixed1, const Fixed &fixed2) //! prototype need check
{
	return (fixed1.toFloat() > fixed2.toFloat() ? fixed1.toFloat() : fixed2.toFloat());
}
