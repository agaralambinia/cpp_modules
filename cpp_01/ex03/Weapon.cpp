#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type)
{
	setType(type);
}

Weapon::Weapon(const Weapon &a)
{
	_type = a.getType();
}

Weapon::~Weapon() {}

Weapon& Weapon::operator=(const Weapon &a)
{
    if (this != &a)
	{
        _type = a.getType();
    }
    return *this;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

const std::string &Weapon::getType() const
{
	return (_type);
}
