#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "WrongCat constructor with type called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &a) : WrongAnimal(a) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &a) {
    if (this != &a)
	{
		WrongAnimal::operator=(a);
    }
	std::cout << "WrongCat assignment constructor called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "WRONG MEOW MEOW" << std::endl;
}
