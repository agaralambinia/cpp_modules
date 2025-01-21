#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &a);
		WrongAnimal &operator=(const WrongAnimal &a);
		virtual ~WrongAnimal();

		void	makeSound() const;
		const std::string	&getType(void) const; 
};

#endif
