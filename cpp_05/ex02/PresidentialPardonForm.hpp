#ifndef  PRESIDENTALPARDONFORM
# define PRESIDENTALPARDONFORM

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &a);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &a);
		~PresidentialPardonForm();

		void execute(const Bureaucrat &executor) const;
};

#endif
