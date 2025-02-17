#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string	_type;

	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &a);
		Cat &operator=(const Cat &a);
		~Cat();

		void	makeSound() const;
};

#endif
