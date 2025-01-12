#include "HumanB.hpp"

static Weapon woWeapon("Default");

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

HumanB::HumanB(const HumanB &a)
{
	_name = a._name;
	_weapon = a._weapon;
}

HumanB::~HumanB() {}

HumanB& HumanB::operator=(const HumanB &a)
{
    if (this != &a)
	{
		_name = a._name;
		_weapon = a._weapon;
    }
    return *this;
}


void HumanB::attack()
{
	std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
