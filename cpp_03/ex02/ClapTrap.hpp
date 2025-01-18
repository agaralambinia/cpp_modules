#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		static const unsigned int	_defaultAttackDamage;
		static const unsigned int	_maxEnergyPoints;
		static const std::string	_defaultName;

	protected:
		ClapTrap(const std::string name, unsigned int maxHP, unsigned int hit_points, const unsigned int energy_points, const unsigned int attack_damage);

		std::string			_name;
		unsigned int		_maxHP;
		unsigned int		_hit_points;
		unsigned int		_energy_points;
		unsigned int		_attack_damage;

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
