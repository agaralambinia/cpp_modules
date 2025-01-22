#ifndef  AFORM
# define AFORM

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string 	_name;
		bool 				_isSigned;
		const int 			_signGrade;
		const int 			_execGrade;

	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &a);
		AForm &operator=(const AForm &a);
		virtual ~AForm();

		std::string getName() const;
		bool		getIsSigned() const;
		int 		getSignGrade() const;
		int 		getExecGrade() const;
		void		setSigned(bool s);

		void 			beSigned(Bureaucrat b);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
