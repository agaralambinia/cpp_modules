#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;

	protected:
		std::string	_type;

	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &a);
		Dog &operator=(const Dog &a);
		~Dog();

		void			makeSound() const;
		std::string 	getIdea(int nbr) const;
		void 			setIdea(int nbr, std::string idea);
};

#endif
