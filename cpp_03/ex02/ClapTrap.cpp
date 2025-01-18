#include "ClapTrap.hpp"

const unsigned int	ClapTrap::_defaultAttackDamage = 0;
const unsigned int	ClapTrap::_maxEnergyPoints = 10;
const std::string	ClapTrap::_defaultName = "ClapTrapNoname";

ClapTrap::ClapTrap() : _name(_defaultName), _maxHP(10), _hit_points(_maxHP), _energy_points(_maxEnergyPoints), _attack_damage(_defaultAttackDamage)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :_name(name), _maxHP(10), _hit_points(_maxHP), _energy_points(_maxEnergyPoints), _attack_damage(_defaultAttackDamage)
{
	std::cout << "ClapTrap constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name, unsigned int maxHP, unsigned int hit_points, const unsigned int energy_points, const unsigned int attack_damage) : _name(name), _maxHP(maxHP), _hit_points(hit_points), _energy_points(energy_points), _attack_damage(attack_damage)
{
	std::cout << "Protected ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &a) : _maxHP(a._maxHP)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = a._name;
	_hit_points = a._hit_points;
	_energy_points = a._energy_points;
	_attack_damage = a._attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &a)
{
	std::cout << "ClapTrap assignment constructor called" << std::endl;
    if (this != &a)
	{
		this->_name = a._name;
		this->_maxHP = a._maxHP;
		this->_hit_points = a._hit_points;
		this->_energy_points = a._energy_points;
		this->_attack_damage = a._attack_damage;
    }
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
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
	else if (this->_hit_points + amount >= this->_maxHP)
	{
		this->_hit_points = this->_maxHP;
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

// getters
unsigned int ClapTrap::getHitPoints() const
{
	return (this->_hit_points);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->_energy_points);
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}
