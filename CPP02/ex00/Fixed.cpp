#include "Fixed.hpp"

Fixed::Fixed(void): //members e.g. member1(initial_value), member2(initial_value)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): //members e.g. member1(other.member1), member2(other.member2) 
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
	// e.g., member1 = other.member1;
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
