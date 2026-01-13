#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
	int _fixedPointNumber; // raw integer representation of the number
	static const int _fractionalBits = 8; // number of bits for the fraction, all the Fixed objects have this same value

	public:
	Fixed(void);
	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

    Fixed(const int fixedIntPointNumber);
    Fixed(const float fixedFloatPointNumber);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
