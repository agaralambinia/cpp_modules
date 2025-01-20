#include "Animal.hpp"

const std::string	Animal::_defaultType = "DefaultAnimal";

Animal::Animal() : _type(_defaultType)
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor with type called" << std::endl;
}

Animal::Animal(const Animal &a)
{
	std::cout << "Animal copy constructor called" << std::endl;
	_type = a._type;
}

Animal &Animal::operator=(const Animal &a)
{
	std::cout << "Animal assignment constructor called" << std::endl;
    if (this != &a)
	{
		this->_type = a._type;
    }
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void	makeSound() {
	std::cout << "You hear an indistinct animal sound. You can't recognize whether it is a cat or a dog... or maybe something more wild..." << std::endl;
}
