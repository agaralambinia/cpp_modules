#include "Bureaucrat.hpp"
#include "Form.hpp"

#define BLUE	"\033[34;1m"
#define RESET	"\033[0m"

int main() {
	
	std::cout << BLUE"Test 1.1: creating a default Form"RESET << std::endl;
	try {
		Form f;
		std::cout << f << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 1.2: creating a parametrized Form"RESET << std::endl;
	try {
		Form f("Offer", 21, 22);
		std::cout << f << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 1.3: creating a parametrized too high level Form - 1"RESET << std::endl;
	try {
		Form f("VeryGoodOffer", 0, 22);
		std::cout << f << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 1.4: creating a parametrized too high level Form - 2"RESET << std::endl;
	try {
		Form f("VeryGoodOffer", 21, 0);
		std::cout << f << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 1.5: creating a parametrized too low level Form - 1"RESET << std::endl;
	try {
		Form f("VeryBadOffer", 21, 151);
		std::cout << f << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 1.6: creating a parametrized too low level Form - 2"RESET << std::endl;
	try {
		Form f("VeryBadOffer", 151, 22);
		std::cout << f << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 2.1: signing a form of OK level"RESET << std::endl;
	try {
		Form f("SomeOffer", 50, 50);
		Form f2("AnotherOffer", 50, 50);
		Bureaucrat b("Burocrat", 40);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		f.beSigned(b);
		std::cout << f << std::endl;
		f.beSigned(b);
		std::cout << f << std::endl;
		std::cout << f2 << std::endl;
		b.signForm(f2);
		std::cout << f2 << std::endl;
		b.signForm(f2);
		std::cout << f2 << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 2.2: signing a form of KO level - 1"RESET << std::endl;
	try {
		Form f("SomeOffer", 50, 50);
		Bureaucrat b("Burocrat", 51);
		std::cout << b << std::endl;
		f.beSigned(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 2.2: signing a form of KO level - 2"RESET << std::endl;
	try {
		Form f("SomeOffer", 50, 50);
		Bureaucrat b("Burocrat", 51);
		std::cout << b << std::endl;
		b.signForm(f);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}