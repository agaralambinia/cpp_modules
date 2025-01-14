#include "Fixed.hpp"

int main(void)
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

	std::cout << std::endl << "*** MORE TESTS ***" << std::endl;
	Fixed c( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const e( Fixed( 5.05f ) - Fixed( 2 ) );
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "(b > a)?: " << (b > a) << std::endl;
	std::cout << "(b < a)?: " << (b < a) << std::endl;
	std::cout << "(a == 100)?: " << (a == 100) << std::endl;
	std::cout << "(a == b)?: " << (a == b) << std::endl;
	std::cout << "(a == a)?: " << (a == a) << std::endl;
	std::cout << "(a != 100)?: " << (a != 100) << std::endl;
	std::cout << "(a != b)?: " << (a != b) << std::endl;
	std::cout << "(a != a)?: " << (a != a) << std::endl;
	std::cout << "(a >= 100)?: " << (a >= 100) << std::endl;
	std::cout << "(a >= b)?: " << (a >= b) << std::endl;
	std::cout << "(a >= a)?: " << (a >= a) << std::endl;
	std::cout << "(a <= 100)?: " << (a <= 100) << std::endl;
	std::cout << "(a <= b)?: " << (a <= b) << std::endl;
	std::cout << "(a <= a)?: " << (a <= a) << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << a << " and " << b << " min is " << Fixed::min( a, b ) << std::endl;
}
