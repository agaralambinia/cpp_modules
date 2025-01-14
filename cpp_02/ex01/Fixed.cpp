#include "Fixed.hpp"
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed() : _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	_number = number << _bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	_number = static_cast<int>(round(number * (1 << _bits)));
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
	return (_number);
}

void Fixed::setRawBits(int const raw)
{
	_number = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_number) / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (_number >> _bits);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed)
{
    ostream << fixed.toFloat();
    return ostream;
}
