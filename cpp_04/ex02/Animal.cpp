#include "Animal.hpp"

Animal::Animal() : type("DefaultAnimal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal constructor with type called" << std::endl;
}

Animal::Animal(const Animal &a) {
	std::cout << "Animal copy constructor called" << std::endl;
	type = a.type;
}

Animal &Animal::operator=(const Animal &a) {
	std::cout << "Animal assignment constructor called" << std::endl;
    if (this != &a)
	{
		this->type = a.type;
    }
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

const std::string	&Animal::getType() const {
	return (this->type);
}
