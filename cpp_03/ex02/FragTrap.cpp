#include "FragTrap.hpp"

const unsigned int	FragTrap::_fragDefaultAttackDamage = 30;
const unsigned int	FragTrap::_fragMaxEnergyPoints = 100;
const std::string	FragTrap::_fragDefaultName = "FragTrapNoname";

FragTrap::FragTrap() : ClapTrap(_fragDefaultName, static_cast<unsigned int>(100), static_cast<unsigned int>(100), _fragMaxEnergyPoints, _fragDefaultAttackDamage)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, static_cast<unsigned int>(100), static_cast<unsigned int>(100), _fragMaxEnergyPoints, _fragDefaultAttackDamage)
{
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &a) : ClapTrap(a)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &a)
{
    if (this != &a)
	{
		ClapTrap::operator=(a);
    }
	std::cout << "FragTrap assignment constructor called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys() const 
{
	if (this->_hit_points && this->_energy_points)
		std::cout << this->_name << " tells you 'High five, Guys!'" << std::endl;
	else
		std::cout << this->_name << " can't high five, he is dead or he doesn't have enough energy(" << std::endl;
}
