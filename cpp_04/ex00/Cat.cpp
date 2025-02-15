#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat constructor with type called" << std::endl;
}

Cat::Cat(const Cat &a) : Animal(a) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &a) {
    if (this != &a)
	{
		Animal::operator=(a);
    }
	std::cout << "Cat assignment constructor called" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "MEOW MEOW" << std::endl;
}
