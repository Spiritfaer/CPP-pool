// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 21:25:15 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 21:25:18 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap {

private:
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
	FragTrap(void);
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & ref);
	~FragTrap(void);

	FragTrap & operator=(FragTrap const & src);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void beWait(void);
	bool beFatigue(void);

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

	/* -------------------------------------------- */
	/* -------------- RANDOM ATTACK --------------- */
	/* -------------------------------------------- */
	void oneAttack(std::string const & target);
	void tripleAttack(std::string const & target);
	void megaAttack(std::string const & target);
	void godlikeAttack(std::string const &target);
	void vziiiiiiipAttack(std::string const &target);

	void vaulthunter_dot_exe(std::string const & target);
};

#endif
