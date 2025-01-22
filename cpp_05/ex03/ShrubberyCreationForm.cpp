#include "ShrubberyCreationForm.hpp"

std::string ShrubberyCreationForm::_asciiTree =
"       ^^^       \n"
"      ^^^^^      \n"
"     ^^^^^^^     \n"
"    ^^^^^^^^^    \n"
"   ^^^^^^^^^^^   \n"
"      |||        \n"
"      |||        ";

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("SOMEONE") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : AForm(a), _target(a._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
	if (this != &a)
	{
		AForm::operator=(a);
		_target = a._target;
    }
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::ofstream	out(_target + "_shrubbery");
	if (!out.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return;
	}
	out << _asciiTree << std::endl;
	out.close();
}
