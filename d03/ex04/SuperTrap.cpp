// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/10/04 17:01:10 by istalevs          #+#    #+#             //
//   Updated: 2019/10/04 17:01:10 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperTrap.hpp"


SuperTrap::SuperTrap(void) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_typeBot = "SuperBot";
	this->_name = "Bot";
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
	std::cout << "Hello I'm your new SuperBot designation SS7Z-XX Hyperion robot class ZZZ, my name " << this->_name << std::endl;
}

SuperTrap::SuperTrap(std::string const & name) : FragTrap(name), NinjaTrap(name) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_typeBot = "SuperBot";
	this->_name = name;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
	std::cout << "Hello I'm your new SuperBot designation SS7Z-XX Hyperion robot class ZZZ, my name " << this->_name << std::endl;
}

SuperTrap::~SuperTrap(void) {
	std::cout << this->_name << " was disappearing..." << std::endl;
}
