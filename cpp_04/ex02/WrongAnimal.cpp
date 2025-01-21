#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("DefaultWrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal constructor with type called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = a.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a) {
	std::cout << "WrongAnimal assignment constructor called" << std::endl;
    if (this != &a)
	{
		this->type = a.type;
    }
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WRONG ANIMAL SOUND" << std::endl;
}

const std::string	&WrongAnimal::getType() const {
	return (this->type);
}
