#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "test.hpp"

#define BLUE_BOLD	"\033[34;1;4m"

int main() {
{
	std::cout << BLUE_BOLD"TESTS FROM SUBJECT"RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}{
	std::cout << BLUE_BOLD"MORE TESTS"RESET << std::endl;

	runTest("Test Animal Class", testAnimal);
    runTest("Test Cat Class", testCat);
    runTest("Test Dog Class", testDog);
	runTest("Test Wrong Animal Class", testWrongAnimal);
    runTest("Test Wrong Cat Class", testWrongCat);

	return 0;
}}
