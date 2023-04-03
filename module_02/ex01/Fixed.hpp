#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"
#include "cmath"

class Fixed{
	friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& exist);
		Fixed& operator=(const Fixed& exist);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
	private:
		int fixedPoint;
		static const int fractionalBits = 8;
};

int getPower(int num, int power);

#endif