#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define GREEN 		"\033[32m"
#define RED 		"\033[31m"
#define PINK		"\033[35m"
#define RESET		"\033[0m"

void runTest(const std::string& testName, bool (*testFunc)());
bool testAnimal();
bool testCat();
bool testDog();
bool testWrongAnimal();
bool testWrongCat();

#endif
