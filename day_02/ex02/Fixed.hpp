#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"
#include "cmath"

class Fixed{
	friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
	public:
		Fixed	();
		Fixed	(const int n);
		Fixed	(const float n);
		Fixed	(const Fixed& exist);
		Fixed&	operator=(const Fixed& exist);
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
		bool	operator>(const Fixed& obj) const;
		bool	operator<(const Fixed& obj) const;
		bool	operator>=(const Fixed& obj) const;
		bool	operator<=(const Fixed& obj) const;
		bool	operator==(const Fixed& obj) const;
		bool	operator!=(const Fixed& obj) const;
		Fixed	operator+(const Fixed& obj) const;
		Fixed	operator-(const Fixed& obj) const;
		Fixed	operator-(void) const;
		Fixed	operator*(const Fixed& obj) const;
		Fixed	operator/(const Fixed& obj) const;
		~Fixed	();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed& min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed& max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);
	private:
		int fixedPoint;
		static const int fractionalBits = 8;
};

int getPower(int num, int power);

#endif