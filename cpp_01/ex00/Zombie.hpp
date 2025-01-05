#include <string>
#include <iostream>

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {
	private:
    	std::string name;

	public:
    	Zombie(std::string a);
    	Zombie(const Zombie &a);
    	~Zombie();
    	Zombie& operator=(const Zombie &a);
 
		void announce( void ); 
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif
