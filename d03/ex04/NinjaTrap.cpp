// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 23:31:17 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 23:31:20 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_typeBot = "Ninja";
	this->_name = "Shadow";
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;
	std::cout << "Hello I'm your new ninja bot designation Hyperion robot class AAA, my name " << this->_name << std::endl;
}

NinjaTrap::NinjaTrap(std::string const & name) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_name = name;
	this->_typeBot = "Ninja";
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;
	std::cout << "Hello I'm your new ninja bot designation Hyperion robot class AAA, my name " << this->_name << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &ref) {
	*this = ref;
	std::cout << "Pandora will be mine!" << std::endl;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "I'll came back..." << std::endl;
}

NinjaTrap& NinjaTrap::operator=(NinjaTrap const &src) {
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


void	NinjaTrap::ninjaShoebox(NinjaTrap const &target) const {
	std::cout << "Crunch " << this->_typeBot << this->_name << " kill..." << target.getName() << std::endl;
};

void	NinjaTrap::ninjaShoebox(FragTrap const &target) const {
	std::cout << "Crunch " << this->_typeBot << this->_name << " kill..." << target.getName() << std::endl;
};

void	NinjaTrap::ninjaShoebox(ScavTrap const &target) const {
	std::cout << "Crunch " << this->_typeBot << this->_name << " kill..." << target.getName() << std::endl;
};

void	NinjaTrap::meleeAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " Ninja melee attacks " << target << " at melee, causing "
			  << this->_meleeAttackDamage << " points of damage!" << std::endl;
}
