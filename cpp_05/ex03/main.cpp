#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#define BLUE	"\033[34;1m"
#define RESET	"\033[0m"

int main() {

	std::cout << BLUE"Test 1.1: Intern creates Forms"RESET << std::endl;
	try {
		Intern i;
		AForm* f1 = i.makeForm("shrubbery creation", "Earth");
		std::cout << *f1 << std::endl;
		delete f1;
		AForm* f2 = i.makeForm("robotomy request", "ROBOT");
		std::cout << *f2 << std::endl;
		delete f2;
		AForm* f3 = i.makeForm("presidential pardon", "you");
		std::cout << *f3 << std::endl;
		delete f3;
		AForm* f4 = i.makeForm("pardon robotomy", "you");
		if (f4 == nullptr) {
            std::cout << "Intern didn't manage it." << std::endl;
        }
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
