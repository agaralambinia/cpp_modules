#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string name);
		HumanB(const HumanB &a);
		~HumanB();
		HumanB& operator=(const HumanB &a);

		void attack();
		void setWeapon(Weapon &weapon);
};

#endif
