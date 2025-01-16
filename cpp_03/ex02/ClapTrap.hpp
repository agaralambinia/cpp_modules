#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		ClapTrap(const std::string name, const unsigned int hit_points, const unsigned int energy_points, const unsigned int attack_damage);

		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	
		static const unsigned int	_maxHP;
		static const unsigned int	_defaultAttackDamage;
		static const unsigned int	_maxEnergyPoints;
		static const std::string	_defaultName;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &a);
		ClapTrap &operator=(const ClapTrap &a);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		unsigned int		getHitPoints() const;
		unsigned int		getEnergyPoints() const;
		std::string			getName() const;
};

#endif
