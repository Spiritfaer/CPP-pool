// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 23:11:05 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 23:11:06 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_typeBot = "Scav";
	this->_name = "Bot";
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
	std::cout << "Hello I'm your new steward bot designation CL4P-TP Hyperion robot class C, my name " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string const & name) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_typeBot = "Scav";
	this->_name = name;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
	std::cout << "Hello I'm your new steward bot designation" << this->_typeBot
	<< "Hyperion robot class D, my name " << this->_name
	<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &ref) {
	*this = ref;
	std::cout << "Oh yeah! More than me!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Life for Ner'zhul" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &src) {
	this->_random = src.getRandom();
	this->_oldRandom = src.getOldRandom();
	this->_hitPoints = src.getHitPoints();
	this->_maxHitPoints = src.getMaxHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_maxEnergyPoints = src.getMaxEnergyPoints();
	this->_level = src.getLevel();
	this->_name = src.getName();
	this->_typeBot = src.getType();
	this->_meleeAttackDamage = src.getMeleeAttackDamage();
	this->_rangedAttackDamage = src.getRangedAttackDamage();
	this->_armorDamageReduction = src.getArmorDamageReduction();
	return *this;
}

void ScavTrap::challengeNewcomer(std::string const & target) {

	long long int rundom;
	rundom = (std::time(nullptr) * _random++) % 5;
	while (this->_oldRandom == rundom)
		rundom = (std::time(nullptr) * _random++) % 5;
	this->_oldRandom = rundom;
	std::string order[] = {
					"Break the wall with your head!",
					"Bring me the grail!",
					"I need two chicks!",
					"Bring me a beer, and some uranium!",
					"Make Gena shave his head!" };
	std::cout << "I order you to " << order[rundom]	<< " right now! Good luck, " << target <<  "... Muahahaha :D" << std::endl;
}
