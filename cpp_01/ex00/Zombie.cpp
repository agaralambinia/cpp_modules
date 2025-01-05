#include "Zombie.hpp"

Zombie::Zombie(std::string a)
{
	name = a;
}

Zombie::Zombie(const Zombie &a)
{
    name = a.name;
}

Zombie::~Zombie()
{
	std::cout
	<< name
	<< " is destroyed!"
	<< std::endl;
}

Zombie& Zombie::operator=(const Zombie &a)
{
    if (this != &a)
	{
        name = a.name;
    }
    return *this;
}

void Zombie::announce( void )
{
	std::cout
	<< name
	<< ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}
