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

AForm *Intern::makeForm(std::string name, std::string target)
{
	int i = 0;
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (i = 0; i < 3; i++)
	{
		if (forms[i] == name)
			break;
	}
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
		{
			std::cout << "Intern doesn't know how to create a form " << name << std::endl;
			return (NULL);
		}
	}
}
