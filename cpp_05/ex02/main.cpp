#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define BLUE	"\033[34;1m"
#define RESET	"\033[0m"

int main() {
	
	std::cout << BLUE"Test 1.1: creating Forms"RESET << std::endl;
	try {
		PresidentialPardonForm f;
		std::cout << f << std::endl;
		RobotomyRequestForm f1;
		std::cout << f1 << std::endl;
		ShrubberyCreationForm f2;
		std::cout << f2 << std::endl;
		PresidentialPardonForm f3("Serega");
		std::cout << f3 << std::endl;
		RobotomyRequestForm f4("Alex");
		std::cout << f4 << std::endl;
		ShrubberyCreationForm f5("Kirill");
		std::cout << f5 << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 1.2: creating Wrong Forms. Commented because it shall not compile."RESET << std::endl;
	// try {
	// 	Form f;
	// 	std::cout << f << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	std::cout << BLUE"Test 2.1: signing a form of OK level"RESET << std::endl;
	try {
		PresidentialPardonForm f;
		std::cout << f << std::endl;
		RobotomyRequestForm f1;
		std::cout << f1 << std::endl;
		ShrubberyCreationForm f2;
		std::cout << f2 << std::endl;
		Bureaucrat b("Burocrat", 25);

		b.signForm(f);
		b.signForm(f1);
		b.signForm(f2);
		std::cout << f << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		b.signForm(f);
		b.signForm(f1);
		b.signForm(f2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 2.2: signing a form of KO level - PresidentialPardonForm"RESET << std::endl;
	try {
		PresidentialPardonForm f;
		std::cout << f << std::endl;
		Bureaucrat b("Burocrat", 26);

		b.signForm(f);
		std::cout << f << std::endl;
		b.signForm(f);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 2.3: signing a form of KO level - RobotomyRequestForm"RESET << std::endl;
	try {
		RobotomyRequestForm f;
		std::cout << f << std::endl;
		Bureaucrat b("Burocrat", 73);

		b.signForm(f);
		std::cout << f << std::endl;
		b.signForm(f);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 2.4: signing a form of KO level - ShrubberyCreationForm"RESET << std::endl;
	try {
		ShrubberyCreationForm f;
		std::cout << f << std::endl;
		Bureaucrat b("Burocrat", 146);

		b.signForm(f);
		std::cout << f << std::endl;
		b.signForm(f);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 3.1: executing an OK form - PresidentialPardonForm"RESET << std::endl;
	try {
		PresidentialPardonForm f;
		std::cout << f << std::endl;
		Bureaucrat b("Burocrat", 1);

		b.signForm(f);
		std::cout << f << std::endl;
		f.execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 3.2: executing an OK form - ShrubberyCreationForm"RESET << std::endl;
	try {
		ShrubberyCreationForm f;
		std::cout << f << std::endl;
		Bureaucrat b("Burocrat", 1);

		b.signForm(f);
		std::cout << f << std::endl;
		f.execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 3.3: executing an OK form - RobotomyRequestForm"RESET << std::endl;
	try {
		RobotomyRequestForm f;
		std::cout << f << std::endl;
		Bureaucrat b("Burocrat", 1);

		b.signForm(f);
		std::cout << f << std::endl;
		f.execute(b);
		f.execute(b);
		f.execute(b);
		f.execute(b);
		f.execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 3.4: executing an KO unsigned form - PresidentialPardonForm"RESET << std::endl;
	try {
		PresidentialPardonForm f;
		std::cout << f << std::endl;
		Bureaucrat b("Burocrat", 1);
		f.execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 3.5: executing an KO unsigned form - ShrubberyCreationForm"RESET << std::endl;
	try {
		ShrubberyCreationForm f;
		std::cout << f << std::endl;
		Bureaucrat b("Burocrat", 1);
		f.execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 3.6: executing an KO unsigned form - RobotomyRequestForm"RESET << std::endl;
	try {
		RobotomyRequestForm f;
		std::cout << f << std::endl;
		Bureaucrat b("Burocrat", 1);
		f.execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 3.7: executing an KO LEVEL form - PresidentialPardonForm"RESET << std::endl;
	try {
		PresidentialPardonForm f;
		std::cout << f << std::endl;
		Bureaucrat bb("GoodBurocrat", 1);
		Bureaucrat bg("BadBurocrat", 150);

		bb.signForm(f);
		std::cout << f << std::endl;
		f.execute(bg);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 3.7: executing an KO LEVEL form - ShrubberyCreationForm"RESET << std::endl;
	try {
		ShrubberyCreationForm f("TEST");
		std::cout << f << std::endl;
		Bureaucrat bb("GoodBurocrat", 1);
		Bureaucrat bg("BadBurocrat", 150);

		bb.signForm(f);
		std::cout << f << std::endl;
		f.execute(bg);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE"Test 3.7: executing an KO LEVEL form - RobotomyRequestForm"RESET << std::endl;
	try {
		RobotomyRequestForm f;
		std::cout << f << std::endl;
		Bureaucrat bb("GoodBurocrat", 1);
		Bureaucrat bg("BadBurocrat", 150);

		bb.signForm(f);
		std::cout << f << std::endl;
		f.execute(bg);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
