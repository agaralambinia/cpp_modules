#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat constructor with type called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &a) : Animal(a) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*(a._brain));
}

Cat &Cat::operator=(const Cat &a) {
    if (this != &a)
	{
		Animal::operator=(a);
		delete _brain;
		_brain = new Brain(*(a._brain));
    }
	std::cout << "Cat assignment constructor called" << std::endl;
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "MEOW MEOW" << std::endl;
}

std::string Cat::getIdea(int nbr) const
{
	if (nbr >= 0 && nbr < 100)
		return (_brain->ideas[nbr]);
	else
		return ("Cat's brain has only 100 (0-99) ideas!");
}

void Cat::setIdea(int nbr, std::string new_idea)
{
	if (nbr >= 0 && nbr < 100)
		_brain->ideas[nbr] = new_idea;
	else
		std::cout << "Cat's brain can have only 100 (0-99) ideas!" << std::endl;
}
