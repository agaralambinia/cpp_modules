#include <string>
#include <iostream>

#ifndef WEAPON_H
# define WEAPON_H

class Weapon {
	private:
    	std::string _type;

	public:
		Weapon();
		Weapon(std::string a);
		Weapon(const Weapon &a);
		~Weapon();
		Weapon& operator=(const Weapon &a);
 
		const std::string &getType(void) const;
		void setType(std::string type); 
};

#endif
