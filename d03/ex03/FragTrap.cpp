// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 23:10:32 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 23:10:33 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_typeBot = "CL4P-TP";
	this->_name = "Trash-man";
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
	std::cout << "Hello I'm your new steward bot designation CL4P-TP Hyperion robot class C, my name " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string const & name) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_name = name;
	this->_typeBot = "CL4P-TP";
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
	std::cout << "Hello I'm your new steward bot designation CL4P-TP Hyperion robot class C, my name " << this->_name << std::endl;
}

FragTrap::FragTrap(FragTrap const &ref) {
	*this = ref;
	std::cout << "Oh yeah! More than me! Pandora will be mine!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "I do not want to die! Nooooo... " << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &src) {
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

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	long long int rundom;
	rundom = (std::time(nullptr) * _random++) % 5;
	while (this->_oldRandom == rundom)
		rundom = (std::time(nullptr) * _random++) % 5;
	this->_oldRandom = rundom;
	if (beFatigue()) {
		switch (rundom) {
			case 0:
				this->oneAttack(target);
				break;
			case 1:
				this->tripleAttack(target);
				break;
			case 2:
				this->megaAttack(target);
				break;
			case 3:
				this->godlikeAttack(target);
				break;
			case 4:
				this->vziiiiiiipAttack(target);
				break;
			default:
				this->meleeAttack(target);
		}
	}
}
