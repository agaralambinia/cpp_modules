#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(const WrongCat &a);
		WrongCat &operator=(const WrongCat &a);
		~WrongCat();

		void	makeSound() const;
};

#endif
