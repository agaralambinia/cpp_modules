#include "AForm.hpp"

AForm::AForm() : _name("DefaultForm"), _isSigned(false), _signGrade(32), _execGrade(15) {}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &a) : _name(a._name), _isSigned(a._isSigned), _signGrade(a._signGrade), _execGrade(a._execGrade) {}

AForm &AForm::operator=(const AForm &a)
{
	if (this != &a)
	{
		this->_isSigned = a._isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecGrade() const
{
	return (this->_execGrade);
}

void AForm::setSigned(bool s)
{
    this->_isSigned = s;
}

void AForm::beSigned(Bureaucrat b)
{
	if (this->getIsSigned())
		std::cout << b.getName() << " couldn't sign form " << this->getName() << " because it is already signed" << std::endl;
	else
	{
		if (b.getGrade() > this->getSignGrade())
			throw AForm::GradeTooLowException();
		else
			this->setSigned(true);
	}
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm exception: grade is too high!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm exception: grade is too low!");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("AForm exception: form can't be executed - it is not signed!");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm " << f.getName() << ", is signed: " << f.getIsSigned() << ", required grade to sign: " << f.getSignGrade() << ", required grade to execute: " << f.getExecGrade();
	return os;
}
