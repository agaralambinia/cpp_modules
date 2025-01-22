#include "Form.hpp"

Form::Form() : _name("DefaultForm"), _isSigned(false), _signGrade(32), _execGrade(15) {}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &a) : _name(a._name), _isSigned(a._isSigned), _signGrade(a._signGrade), _execGrade(a._execGrade) {}

Form &Form::operator=(const Form &a)
{
	if (this != &a)
	{
		this->_isSigned = a._isSigned;
	}
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

void Form::setSigned(bool s)
{
    this->_isSigned = s;
}

void Form::beSigned(Bureaucrat b)
{
	if (this->getIsSigned())
		std::cout << b.getName() << " couldn't sign form " << this->getName() << " because it is already signed" << std::endl;
	else
	{
		if (b.getGrade() > this->getSignGrade())
			throw Form::GradeTooLowException();
		else
			this->setSigned(true);
	}
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form exception: grade is too high!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form exception: grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form " << f.getName() << ", is signed: " << f.getIsSigned() << ", required grade to sign: " << f.getSignGrade() << ", required grade to execute: " << f.getExecGrade();
	return os;
}
