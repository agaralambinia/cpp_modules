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
	float j = 5;
	--j = 5.05f;
	Fixed g(5);
	--g = Fixed(5.05f);
	std::cout << "--5 = 5.05f: " << j << std::endl;
	std::cout << "--5(fixed) = 5.05f: " << g << std::endl;
	--c = 3;
	std::cout << "--c = 3: " << c << std::endl;
	std::cout << a << " and " << b << " min is " << Fixed::min( a, b ) << std::endl;
	std::cout << "COMMENTED TESTS THAT SHALL NOT WORK" << std::endl;
	// int i1 = 5;
	// int i2 = 6;
	// i1+i2=100;
	// Fixed f1(5);
	// Fixed f2(6);
	// f1+f2 = 100;
	// i1-i2=100;
	// f1-f2 = 100;
	// i1*i2=100;
	// f1*f2 = 100;
	// i1/i2=100;
	// f1/f2 = 100;
	// i1>i2=100;
	// i1<i2=100;
}
