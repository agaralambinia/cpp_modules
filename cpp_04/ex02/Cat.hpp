#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;

	protected:
		std::string	_type;

	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &a);
		Cat &operator=(const Cat &a);
		~Cat();

		void			makeSound() const;
		std::string 	getIdea(int nbr) const;
		void 			setIdea(int nbr, std::string idea);
};

#endif
