#include "ClapTrap.hpp"

const unsigned int	ClapTrap::_maxHP = 10;

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	_name = "NoName";
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor with name called" << std::endl;
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &a)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = a._name;
	_hit_points = a._hit_points;
	_energy_points = a._energy_points;
	_attack_damage = a._attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &a)
{
	std::cout << "Assignment constructor called" << std::endl;
    if (this != &a)
	{
		this->_name = a._name;
		this->_hit_points = a._hit_points;
		this->_energy_points = a._energy_points;
		this->_attack_damage = a._attack_damage;
    }
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hit_points == 0)
		std::cout << this->_name << " has no hit points. He is dead!" << std::endl;
	else if (this->_energy_points == 0)
		std::cout << this->_name << " doesn't have energy points to attack!" << std::endl;
	else
	{
		this->_energy_points -= 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0 && amount != 0)
		std::cout << this->_name << " has no hit points. He can't be more damaged!" << std::endl;
	else if (amount > this->_hit_points)
	{
		std::cout << "ClapTrap " << this->_name << " had " << this->_hit_points << " hit points, so " << amount << " points of damage killed him!" << std::endl;
		this->_hit_points = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
		this->_hit_points -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0)
		std::cout << this->_name << " is dead. He can't be repaired" << std::endl;
	else if (this->_energy_points == 0)
		std::cout << this->_name << " has not enough energy points to be repaired" << std::endl;
	else if (this->_hit_points + amount >= _maxHP)
	{
		this->_hit_points = 10;
		this->_energy_points -= 1;
		std::cout << "ClapTrap " << this->_name << " is has max HP!" << std::endl;
	}
	else
	{
		this->_hit_points += amount;
		this->_energy_points -= 1;
		std::cout << "ClapTrap " << this->_name << " repaired " << amount << " hit points!" << std::endl;
	}
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->_hit_points);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->_energy_points);
}
