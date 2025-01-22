#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &a) {
	(void)a;
}

Intern &Intern::operator=(const Intern &a)
{
	if (this != &a) {}
	return (*this);
}

Intern::~Intern() {}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *(*forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (name == form_names[i]) {
			return (forms[i](target));
		}
	}
	std::cout << "Intern doesn't know how to create a form " << name << std::endl;
	return NULL;
}
