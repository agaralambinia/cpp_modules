#ifndef  FORM
# define FORM

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool 				_isSigned;
		const int 			_signGrade;
		const int 			_execGrade;

	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &a);
		Form &operator=(const Form &a);
		~Form();

		std::string getName() const;
		bool		getIsSigned() const;
		int 		getSignGrade() const;
		int 		getExecGrade() const;
		void		setSigned(bool s);

		void beSigned(Bureaucrat b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
