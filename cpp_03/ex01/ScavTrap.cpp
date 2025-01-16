// #include "ScavTrap.hpp"

// const unsigned int	ScavTrap::_scavMaxHP = 100;
// const unsigned int	ScavTrap::_scavDefaultAttackDamage = 20;
// const unsigned int	ScavTrap::_scavMaxEnergyPoints = 50;
// const std::string	ScavTrap::_scavDefaultName = "ScavTrapNoname";

// ScavTrap::ScavTrap() : ClapTrap(_scavDefaultName, _scavMaxHP, _scavMaxEnergyPoints, _scavDefaultAttackDamage)
// {
// 	std::cout << "ScavTrap default constructor called" << std::endl;
// }

// ScavTrap::ScavTrap(std::string name) : ClapTrap(name, _scavMaxHP, _scavMaxEnergyPoints, _scavDefaultAttackDamage)
// {
// 	std::cout << "ScavTrap name constructor called" << std::endl;
// }

// ScavTrap::ScavTrap(const ScavTrap &a) : ClapTrap(a)
// {
// 	std::cout << "ScavTrap copy constructor called" << std::endl;
// }

// ScavTrap &ScavTrap::operator=(const ScavTrap &a)
// {
//     if (this != &a)
// 	{
// 		ClapTrap::operator=(a);
//     }
// 	std::cout << "ScavTrap assignment constructor called" << std::endl;
// 	return (*this);
// }

// ClapTrap::~ClapTrap() {
// 	std::cout << "ScavTrap destructor called" << std::endl;
// }

// // void ClapTrap::attack(const std::string &target)
// // {
// // 	if (this->_hit_points == 0)
// // 		std::cout << this->_name << " has no hit points. He is dead!" << std::endl;
// // 	else if (this->_energy_points == 0)
// // 		std::cout << this->_name << " doesn't have energy points to attack!" << std::endl;
// // 	else
// // 	{
// // 		this->_energy_points -= 1;
// // 		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
// // 	}
// // }

// void	ScavTrap::guardGate() const
// {
// 	if (this->_hit_points && this->_energy_points)
// 		std::cout << this->_name << " is now in Gate keeper mode." << std::endl;
// }
