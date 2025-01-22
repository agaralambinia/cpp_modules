#ifndef  BUREAUCRAT
# define BUREAUCRAT

#include <iostream>
#include <string>
#include <exception>
#include <ostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &a);
        Bureaucrat &operator=(const Bureaucrat &a);
        ~Bureaucrat();
	
        std::string getName() const;
        int 		getGrade() const;
        void 		incrementGrade();
        void 		decrementGrade();
        void        signForm(Form &form);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &a);

#endif
