#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	private:
		static const std::string	_defaultType;

	protected:
		std::string	_type;

	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &a);
		Animal &operator=(const Animal &a);
		virtual ~Animal();

		virtual void	makeSound();
};

#endif
