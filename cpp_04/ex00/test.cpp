#include "test.hpp"

void runTest(const std::string& testName, bool (*testFunc)()) {
    std::cout << PINK << testName << RESET << std::endl;
    if (testFunc()) {
        std::cout << GREEN << "Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Error" << RESET << std::endl;
    }
}

bool testAnimal() {
    try {
        Animal* animalPtr = new Animal("Cow");
        delete animalPtr;
        Animal defaultAnimal;
        Animal parameterizedAnimal("Elephant");
        Animal copiedAnimal(parameterizedAnimal);
        Animal assignedAnimal;
        assignedAnimal = defaultAnimal;
		defaultAnimal.makeSound(); // Should print NOTHING
		parameterizedAnimal.makeSound(); // Should print NOTHING
		copiedAnimal.makeSound(); // Should print NOTHING
        return true;
    } catch (...) {
        return false;
    }
}

bool testCat() {
    try {
		Cat* catPtr = new Cat("Abessin");
        delete catPtr;

        Cat cat1;
        cat1.makeSound(); // Should print "MEOW MEOW"

        Cat cat2("White");
        cat2.makeSound(); // Should print "MEOW MEOW"

        Cat cat3(cat2);
        cat3.makeSound(); // Should print "MEOW MEOW"

        cat1 = cat2;
        cat1.makeSound(); // Should print "MEOW MEOW"

        return true;
    } catch (...) {
        return false;
    }
}

bool testDog() {
    try {
		Dog* dogPtr = new Dog("Labrador");
        delete dogPtr;

        Dog dog1;
        dog1.makeSound(); // Should print "BARK BARK"

        Dog dog2("Bulldog");
        dog2.makeSound(); // Should print "BARK BARK"

        Dog dog3(dog2);
        dog3.makeSound(); // Should print "BARK BARK"

        dog1 = dog2;
        dog1.makeSound(); // Should print "BARK BARK"

        return true;
    } catch (...) {
        return false;
    }
}

bool testWrongAnimal() {
    try {
        WrongAnimal* wanimalPtr = new WrongAnimal("Cow");
        delete wanimalPtr;
        WrongAnimal defaultwAnimal;
        WrongAnimal parameterizedwAnimal("Elephant");
        WrongAnimal copiedwAnimal(parameterizedwAnimal);
        WrongAnimal assignedwAnimal;
        assignedwAnimal = defaultwAnimal;
		defaultwAnimal.makeSound(); // Should print NOTHING
		parameterizedwAnimal.makeSound(); // Should print NOTHING
		copiedwAnimal.makeSound(); // Should print NOTHING
        return true;
    } catch (...) {
        return false;
    }
}

bool testWrongCat() {
    try {
		WrongCat* wcatPtr = new WrongCat("Abessin");
        delete wcatPtr;

        WrongCat cat1;
        cat1.makeSound(); // Should print "MEOW MEOW"

        WrongCat cat2("White");
        cat2.makeSound(); // Should print "MEOW MEOW"

        WrongCat cat3(cat2);
        cat3.makeSound(); // Should print "MEOW MEOW"

        cat1 = cat2;
        cat1.makeSound(); // Should print "MEOW MEOW"

        return true;
    } catch (...) {
        return false;
    }
}
