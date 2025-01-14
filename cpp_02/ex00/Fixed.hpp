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
		Fixed &operator=(const Fixed &a);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
