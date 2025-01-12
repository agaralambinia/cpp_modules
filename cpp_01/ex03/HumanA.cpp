#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	_name = name;
}

HumanA::HumanA(const HumanA &a) : _weapon(a._weapon)
{
	_name = a._name;
}

HumanA::~HumanA() {}

HumanA& HumanA::operator=(const HumanA &a)
{
    if (this != &a)
	{
		_name = a._name;
		_weapon = a._weapon;
    }
    return *this;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
