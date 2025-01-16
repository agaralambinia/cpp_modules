#include "Fixed.hpp"
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed() : _number(0) {}

Fixed::Fixed(const int number)
{
	_number = number << _bits;
}

Fixed::Fixed(const float number)
{
	_number = static_cast<int>(round(number * (1 << _bits)));
}

Fixed::Fixed(const Fixed &a)
{
	*this = a;
}

Fixed &Fixed::operator=(const Fixed &a)
{
    if (this != &a)
	{
		setRawBits(a.getRawBits());
    }
	return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
	return (_number);
}

void Fixed::setRawBits(int const raw)
{
	_number = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_number) / (1 << _bits));
}

int Fixed::toInt() const
{
	return (_number >> _bits);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return const_cast<Fixed&>(Fixed::min(static_cast<const Fixed&>(a), static_cast<const Fixed&>(b)));
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return const_cast<Fixed&>(Fixed::max(static_cast<const Fixed&>(a), static_cast<const Fixed&>(b)));
}


bool Fixed::operator>(const Fixed &a) const
{
	return (_number > a._number);
}

bool Fixed::operator<(const Fixed &a) const
{
	return (_number < a._number);
}

bool Fixed::operator>=(const Fixed &a) const
{
	return (_number >= a._number);
}

bool Fixed::operator<=(const Fixed &a) const
{
	return (_number <= a._number);
}

bool Fixed::operator==(const Fixed &a) const
{
	return (_number == a._number);
}

bool Fixed::operator!=(const Fixed &a) const
{
	return (_number != a._number);
}

Fixed Fixed::operator+(const Fixed &a) const
{
	return (Fixed(toFloat() + a.toFloat()));
}

Fixed Fixed::operator-(const Fixed &a) const
{
	return (Fixed(toFloat() - a.toFloat()));
}

Fixed Fixed::operator*(const Fixed &a) const
{
	return (Fixed(toFloat() * a.toFloat()));
}

Fixed Fixed::operator/(const Fixed &a) const
{
	return (Fixed(toFloat() / a.toFloat()));
}

Fixed &Fixed::operator++()
{
	_number++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed newthis(*this);
	++(*this);
	return (newthis);
}

Fixed &Fixed::operator--()
{
	_number--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed newthis(*this);
	--(*this);
	return (newthis);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed)
{
    ostream << fixed.toFloat();
    return ostream;
}
