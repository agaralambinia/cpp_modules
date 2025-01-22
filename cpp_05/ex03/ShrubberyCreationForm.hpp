#ifndef  SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string 		_target;
		static std::string	_asciiTree;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &a);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat &executor) const;
};

#endif
