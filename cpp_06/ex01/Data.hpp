#ifndef DATA_HPP
# define DATA_HPP

#include <string>

struct Data
{
	std::string 		product;
	int					amount;
	double				price;
	bool				available_flg;
	unsigned long long	id;
};

#endif
