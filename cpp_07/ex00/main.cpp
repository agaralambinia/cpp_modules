// TODO: что делать с const?
#include "whatever.hpp"

#define BLUE	"\033[34;1m"
#define GREEN 	"\033[32m"
#define RESET	"\033[0m"

int main( void ) {
std::cout << BLUE"TESTS FROM SUBJECT"RESET << std::endl;
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

std::cout << std::endl << BLUE"MORE TESTS"RESET << std::endl;
{
	std::cout << std::endl << GREEN"static int"RESET << std::endl;

	const int a = 2;
    const int b = 3;
	std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
	//::swap( a, b );
	std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min: " << ::min( a, b ) << std::endl;
    std::cout << "max: " << ::max( a, b ) << std::endl;
}

{
	std::cout << std::endl << GREEN"signed char"RESET << std::endl;

	signed char a = 'c';
    signed char b = 'd';
	std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min: " << ::min( a, b ) << std::endl;
    std::cout << "max: " << ::max( a, b ) << std::endl;
}

{
	std::cout << std::endl << GREEN"unsigned char"RESET << std::endl;

	unsigned char a = 'c';
    unsigned char b = 'd';
	std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min: " << ::min( a, b ) << std::endl;
    std::cout << "max: " << ::max( a, b ) << std::endl;
}

{
	std::cout << std::endl << GREEN"char"RESET << std::endl;

	char a = 'c';
    char b = 'd';
	std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min: " << ::min( a, b ) << std::endl;
    std::cout << "max: " << ::max( a, b ) << std::endl;
}

{
	std::cout << std::endl << GREEN"short"RESET << std::endl;

	short a = 3;
    short b = 4;
	std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min: " << ::min( a, b ) << std::endl;
    std::cout << "max: " << ::max( a, b ) << std::endl;
}

{
	std::cout << std::endl << GREEN"bool"RESET << std::endl;

	bool a = true;
    bool b = false;
	std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min: " << ::min( a, b ) << std::endl;
    std::cout << "max: " << ::max( a, b ) << std::endl;
}

{
	std::cout << std::endl << GREEN"float"RESET << std::endl;

	float a = 2.1f;
    float b = 3.1f;
	std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min: " << ::min( a, b ) << std::endl;
    std::cout << "max: " << ::max( a, b ) << std::endl;
}

return 0;
}
