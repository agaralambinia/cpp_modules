#include "Bureaucrat.hpp"

#define BLUE	"\033[34;1m"
#define RESET	"\033[0m"

int main() {
	std::cout << BLUE"Test 1.1: creating a default Bureaucrat"RESET << std::endl;
	try {
		Bureaucrat b;
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << BLUE"Test 1.2: creating a parametrized Bureaucrat"RESET << std::endl;
	try {
		Bureaucrat b("Serega", 10);
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << BLUE"Test 1.3: creating a parametrized too high level Bureaucrat"RESET << std::endl;
	try {
		Bureaucrat b("Alex", 0);
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << BLUE"Test 1.4: creating a parametrized too low level Bureaucrat"RESET << std::endl;
	try {
		Bureaucrat b("Segfault", 151);
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << BLUE"Test 2.1: incrementing and decrementing grade in ranges"RESET << std::endl;
	try {
		Bureaucrat b("Serega", 10);
		std::cout << "Bureaucrat stats before manipulations: " << b << std::endl;
		b.incrementGrade();
		std::cout << "Bureaucrat stats after increment: " << b << std::endl;
		b.decrementGrade();
		std::cout << "Bureaucrat stats after decrement: " << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << BLUE"Test 2.2: incrementing out of ranges"RESET << std::endl;
	try {
		Bureaucrat b("Alex", 1);
		std::cout << "Bureaucrat stats before manipulations: " << b << std::endl;
		b.incrementGrade();
		std::cout << "Bureaucrat stats after increment: " << b << std::endl;
		b.decrementGrade();
		std::cout << "Bureaucrat stats after decrement: " << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << BLUE"Test 2.3: decrementing out of ranges"RESET << std::endl;
	try {
		Bureaucrat b("Segfault", 150);
		std::cout << "Bureaucrat stats before manipulations: " << b << std::endl;
		b.decrementGrade();
		std::cout << "Bureaucrat stats after decrement: " << b << std::endl;
		b.incrementGrade();
		std::cout << "Bureaucrat stats after increment: " << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}