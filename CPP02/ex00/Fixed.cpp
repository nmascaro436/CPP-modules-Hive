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
