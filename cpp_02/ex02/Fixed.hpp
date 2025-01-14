#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_number;
		static const int	_bits;

	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &a);
		Fixed &operator = (const Fixed &a);
		~Fixed();

		int					getRawBits() const;
		void				setRawBits(int const raw);
		float				toFloat() const;
		int					toInt() const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		bool operator > (const Fixed &a) const;
		bool operator < (const Fixed &a) const;
		bool operator >= (const Fixed &a) const;
		bool operator <= (const Fixed &a) const;
		bool operator == (const Fixed &a) const;
		bool operator != (const Fixed &a) const;

		Fixed operator + (const Fixed &a) const;
		Fixed operator - (const Fixed &a) const;
		Fixed operator * (const Fixed &a) const;
		Fixed operator / (const Fixed &a) const;

		Fixed operator ++ ();
		Fixed operator ++ (int);
		Fixed operator -- ();
		Fixed operator -- (int);
};

std::ostream &operator<<(std::ostream &ostream,  Fixed const &fixed);

#endif
