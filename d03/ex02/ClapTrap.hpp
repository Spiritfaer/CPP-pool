// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 23:10:19 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 23:10:20 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	int	_random;
	int	_oldRandom;
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	unsigned int _meleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorDamageReduction;
	std::string _typeBot;
	std::string _name;

public:
	ClapTrap( void );
	ClapTrap ( std::string const & name );
	ClapTrap (ClapTrap const & src);
	~ClapTrap( void );

	ClapTrap & operator=(ClapTrap const & dst);

	unsigned int getHitPoints(void) const;
	unsigned int getMaxHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getMaxEnergyPoints(void) const;
	unsigned int getLevel(void) const;
	std::string getName(void) const;
	std::string getType(void) const;
	unsigned int getMeleeAttackDamage(void) const;
	unsigned int getRangedAttackDamage(void) const;
	unsigned int getArmorDamageReduction(void) const;
	int getRandom(void) const;
	int getOldRandom(void) const;

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void beWait(void);
	bool beFatigue(void);

	void oneAttack(std::string const & target);
	void tripleAttack(std::string const & target);
	void megaAttack(std::string const & target);
	void godlikeAttack(std::string const &target);
	void vziiiiiiipAttack(std::string const &target);
};


#endif
