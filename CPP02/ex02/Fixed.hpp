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

	// Comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Increment / decrement operators
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	// Min / max functions
	static Fixed& min(Fixed& num1, Fixed& num2);
	static const Fixed& min(const Fixed& num1, const Fixed& num2);
	static Fixed& max(Fixed& num1, Fixed& num2);
	static const Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
