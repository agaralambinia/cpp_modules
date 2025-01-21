#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
		Brain();
		Brain(const Brain &a);
		Brain &operator=(const Brain &a);
        ~Brain();

		std::string ideas[100];
};

#endif
