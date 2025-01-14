#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed &Fixed::operator=(const Fixed &a)
{
	std::cout << "Copy assignment constructor called" << std::endl;
    if (this != &a)
	{
		setRawBits(a.getRawBits());
    }
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_number);
}

void Fixed::setRawBits(int const raw)
{
	_number = raw;
}
