#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog constructor with type called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &a) : Animal(a) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*(a._brain));
}

Dog &Dog::operator=(const Dog &a) {
    if (this != &a)
	{
		Animal::operator=(a);
		delete _brain;
		_brain = new Brain(*(a._brain));
    }
	std::cout << "Dog assignment constructor called" << std::endl;
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "BARK BARK" << std::endl;
}

std::string Dog::getIdea(int nbr) const
{
	if (nbr >= 0 && nbr < 100)
		return (_brain->ideas[nbr]);
	else
		return ("Dog's brain has only 100 (0-99) ideas!");
}

void Dog::setIdea(int nbr, std::string new_idea)
{
	if (nbr >= 0 && nbr < 100)
		_brain->ideas[nbr] = new_idea;
	else
		std::cout << "Dog's brain can have only 100 (0-99) ideas!" << std::endl;
}
