#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	protected:
		static const unsigned int	_fragMaxHP;
		static const unsigned int	_fragDefaultAttackDamage;
		static const unsigned int	_fragMaxEnergyPoints;
		static const std::string	_fragDefaultName;

	public:
		FragTrap();
		FragTrap(const FragTrap &a);
		FragTrap(const std::string name);
		FragTrap	&operator=(const FragTrap &a);
		~FragTrap();

		void		highFivesGuys() const;
		void		guardGate() const;
		void		attack(const std::string &target);
};

#endif
