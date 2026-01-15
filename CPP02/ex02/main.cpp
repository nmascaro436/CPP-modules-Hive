#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
/*
int main()
{
	Fixed x(5);
	Fixed y(10);

	// Test comparison operators
	std::cout << (x < y) << std::endl;   // Should print 1 (true)
	std::cout << (x > y) << std::endl;   // Should print 0 (false)
	std::cout << (x == y) << std::endl;  // Should print 0 (false)

	// Test addition/subtraction/division
	std::cout << (x + y) << std::endl;   // Should print 15
	std::cout << (y - x) << std::endl;   // Should print 5
	std::cout << (y / x) << std::endl;   // Should print 2

	// Test decrement
	std::cout << --x << std::endl;
	std::cout << x-- << std::endl;

	// Test min
	std::cout << Fixed::min(x, y) << std::endl;
} */
