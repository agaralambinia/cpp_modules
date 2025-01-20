#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		static const std::string	_defaultType;

	protected:
		std::string	_type;

	public:
		Cat();
		Cat(std::string name);
		Cat(const Animal &a);
		Animal &operator=(const Animal &a);
		~Animal();

		void	makeSound();
};

#endif
