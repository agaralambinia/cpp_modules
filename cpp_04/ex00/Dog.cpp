#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog constructor with type called" << std::endl;
}

Dog::Dog(const Dog &a) : Animal(a) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &a) {
    if (this != &a)
	{
		Animal::operator=(a);
    }
	std::cout << "Dog assignment constructor called" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "BARK BARK" << std::endl;
}
