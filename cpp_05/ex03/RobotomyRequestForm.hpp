#ifndef  ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &a);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &a);
		~RobotomyRequestForm();

		void execute(const Bureaucrat &executor) const;
};

#endif
