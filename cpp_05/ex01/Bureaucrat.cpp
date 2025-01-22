#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &a) : _name(a._name), _grade(a._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a)
{
	if (this != &a)
	{
		this->_grade = a._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	std::cout << "Incrementing grade of Bureaucrat " << this->getName() << std::endl;
	if (--(this->_grade) < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Decrementing grade of Bureaucrat " << this->getName() << std::endl;
	if (++(this->_grade) > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
	bool flg = form.getIsSigned();
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return;
    }
	if (!flg)
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Exception: grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Exception: grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << "Name " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
