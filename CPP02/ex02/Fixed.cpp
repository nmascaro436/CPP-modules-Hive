#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): _fixedPointNumber(other._fixedPointNumber)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
	    _fixedPointNumber = other._fixedPointNumber;
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointNumber;
}

void Fixed::setRawBits(int const raw)
{
        _fixedPointNumber = raw;
}
/**
 * Creates a Fixed object directly from an int.
 * Converts the integer to a fixed point number by shifting 1 in binary to the left 8 times.
*/ 
Fixed::Fixed(const int fixedIntPointNumber)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointNumber = fixedIntPointNumber * (1 << _fractionalBits);
}
/**
 * Creates a Fixed object directly from an float.
 * Converts the float to a fixed point number by shifting 1 in binary to the left 8 times.
 * Roundf rounds to the nearest whole number so the fixed-point is as accurate as possible.
*/ 
Fixed::Fixed(const float fixedFloatPointNumber)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointNumber = roundf(fixedFloatPointNumber * (1 << _fractionalBits));
}
/**
 * Converts the fixed-point number to a float number.
 */
float Fixed::toFloat(void) const
{
    return (float) _fixedPointNumber / (1 << _fractionalBits);
}

/**
 * Converts the fixed-point number to an integer.
 * Doing >> means dropping the last x number of bits (which are storing the decimal part),
 * could also express it like this _fixedPointNumber / (1 << _fractionalBits)
 */
int Fixed::toInt(void) const
{
    return _fixedPointNumber >> _fractionalBits;
}

/**
 * Inserts the float representation of the Fixed object into the output stream.
 */
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

/**
 * Returns true if this Fixed number is greater than 'other', false otherwise.
 * The last const ensures the function doesn't modify the object it's called on.
 */
bool Fixed::operator>(const Fixed& other) const
{
    return this->_fixedPointNumber > other._fixedPointNumber;
}

/**
 * Returns true if this Fixed number is less than 'other', false otherwise.
 */
bool Fixed::operator<(const Fixed& other) const
{
    return this->_fixedPointNumber < other._fixedPointNumber;
}

/**
 * Returns true if this Fixed number is greater than or equal to 'other', false otherwise.
 */
bool Fixed::operator>=(const Fixed& other) const
{
    return this->_fixedPointNumber >= other._fixedPointNumber;
}

/**
 * Returns true if this Fixed number is less than or equal to 'other', false otherwise.
 */
bool Fixed::operator<=(const Fixed& other) const
{
    return this->_fixedPointNumber <= other._fixedPointNumber;
}

/**
 * Returns true if this Fixed number is equal to 'other', false otherwise.
 */
bool Fixed::operator==(const Fixed& other) const
{
    return this->_fixedPointNumber == other._fixedPointNumber;
}

/**
 * Returns true if this Fixed number is not equal to 'other', false otherwise.
 */
bool Fixed::operator!=(const Fixed& other) const
{
    return this->_fixedPointNumber != other._fixedPointNumber;
}

/**
 * Adds two Fixed numbers and returns the result as a new Fixed object.
 */
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result._fixedPointNumber = this->_fixedPointNumber + other._fixedPointNumber;
    return result;
}

/**
 * Substracts another Fixed number from this Fixed number and returns the result 
 * as a new Fixed object.
 */
Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result._fixedPointNumber = this->_fixedPointNumber - other._fixedPointNumber;
    return result;
}

/**
 * Multiplies two Fixed numbers and returns the result as a new Fixed object.
 * 
 */
Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result._fixedPointNumber = (this->_fixedPointNumber * other._fixedPointNumber) >> _fractionalBits;
    return result;
}

/**
 * Divides this Fixed number by another Fixed number and returns the result as
 * a new Fixed object.
 * 
 */
Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result._fixedPointNumber = (this->_fixedPointNumber << _fractionalBits) / other._fixedPointNumber;
    return result;
}

/**
 * Pre-increment
 */
Fixed& Fixed::operator++()
{

}

/**
 * Post-increment
 */
Fixed Fixed::operator++(int)
{

}

/**
 * Pre-decrement
 */
Fixed& Fixed::operator--()
{

}

/**
 * Post-decrement
 */
Fixed Fixed::operator--(int)
{

}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{

}
const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{

}
Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{

}
Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{

}
