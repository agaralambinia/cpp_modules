#include <string>
#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {
	private:
    	std::string name;

	public:
		Zombie();
    	Zombie(std::string a);
    	Zombie(const Zombie &a);
    	~Zombie();
    	Zombie& operator=(const Zombie &a);
 
		void announce( void ); 
};

Zombie *zombieHorde( int N, std::string name );

#endif
