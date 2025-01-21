#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	protected:
		std::string	_type;

	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &a);
		Dog &operator=(const Dog &a);
		~Dog();

		void	makeSound() const;
};

#endif
