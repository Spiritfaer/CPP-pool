// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 21:25:09 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 21:25:10 by istalevs         ###   ########.fr       //
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

FragTrap::FragTrap(std::string const & name) : _name(name) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
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

unsigned int FragTrap::getHitPoints() const { return this->_hitPoints; }
unsigned int FragTrap::getMaxHitPoints() const { return this->_maxHitPoints; }
unsigned int FragTrap::getEnergyPoints() const { return this->_energyPoints; }
unsigned int FragTrap::getMaxEnergyPoints() const { return this->_maxEnergyPoints; }
unsigned int FragTrap::getLevel() const { return this->_level; }
std::string FragTrap::getName() const { return this->_name; }
std::string FragTrap::getType() const { return this->_typeBot; }
unsigned int FragTrap::getMeleeAttackDamage() const { return this->_meleeAttackDamage; }
unsigned int FragTrap::getRangedAttackDamage() const { return this->_rangedAttackDamage; }
unsigned int FragTrap::getArmorDamageReduction() const { return this->_armorDamageReduction; }
int FragTrap::getRandom() const { return this->_random; }
int FragTrap::getOldRandom() const { return this->_oldRandom; }

void FragTrap::rangedAttack(std::string const &target) {
	std::cout << this->_typeBot << " " << this->_name << " attacks " << target << " at range, causing "
	<< this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " attacks " << target << " at melee, causing "
	<< this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints < amount - this->_armorDamageReduction) {
		this->_hitPoints = 0;
		std::cout << "F***! I got " << amount << " damage, and now I have " << this->_hitPoints << " hit points" << std::endl;
	}
	else {
		this->_hitPoints -= amount - this->_armorDamageReduction;
		std::cout << "Master! I got " << amount << " damage, and now I have " << this->_hitPoints << " hit points" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == this->_maxHitPoints) {
		std::cout << "Tnx! But I look like a new penny" << std::endl;
	}
	else if (this->_hitPoints + amount > this->_maxHitPoints) {
		this->_hitPoints = this->_maxHitPoints;
		std::cout << "Tnx! I got " << amount << " healed, and now I have " << this->_hitPoints << " hit points" << std::endl;
	}
	else {
		this->_hitPoints += amount;
		std::cout << "Tnx! I got " << amount << " healed, and now I have " << this->_hitPoints << " hit points" << std::endl;
	}
}

void FragTrap::beWait() {
	if (this->_energyPoints == this->_maxEnergyPoints) {
		std::cout << "I do not wait! My battery is charged..." << std::endl;
	}
	else if (this->_energyPoints + 20 > this->_maxEnergyPoints) {
		this->_energyPoints = this->_maxHitPoints;
		std::cout << "Tnx! Now my battery is charged..." << std::endl;
	}
	else {
		this->_energyPoints += 20;
		std::cout << "Tnx! Now my battery level " << this->_energyPoints << " energy points" << std::endl;
	}
}

bool FragTrap::beFatigue() {
	if (this->_energyPoints == 0)
		std::cout << "F*** off! I SAID I MUST TO REST!" << std::endl;
	else if (this->_energyPoints < 25) {
		this->_energyPoints = 0;
		std::cout << "Master! I loose all my energy! I shod rest!" << std::endl;
	}
	else {
		this->_energyPoints -= 25;
		std::cout << "I loose my energy, and now I have " << this->_energyPoints << " energy points" << std::endl;
		return true;
	}
	return false;
}
/* -------------------------------------------- */
/* ------------------ ATTACK ------------------ */
/* -------------------------------------------- */

void FragTrap::oneAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " use one attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 1 << " points of damage!" << std::endl;
}
void FragTrap::tripleAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " use triple attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 3 << " points of damage!" << std::endl;
}
void FragTrap::megaAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " use mega attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage  * 5.5 << " points of damage!" << std::endl;
}
void FragTrap::godlikeAttack(std::string const &target) {
	std::cout << this->_typeBot << " " << this->_name << " use godlike attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 10 << " points of damage!" << std::endl;
}
void FragTrap::vziiiiiiipAttack(std::string const &target) {
	std::cout << this->_typeBot << " " << this->_name << " use vziiiiiiip attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 0.5 << " points of damage!" << std::endl;
}

/* -------------------------------------------- */
/* -------------- RANDOM ATTACK --------------- */
/* -------------------------------------------- */
void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	long long int rundom;
	rundom = (std::time(nullptr) * _random++) % 5;
	while (this->_oldRandom == rundom)
		rundom = (std::time(nullptr) * _random++) % 5;
	this->_oldRandom = rundom;
	if (beFatigue()) {
		switch (rundom) {
			case 0:
				oneAttack(target);
				break;
			case 1:
				tripleAttack(target);
				break;
			case 2:
				megaAttack(target);
				break;
			case 3:
				godlikeAttack(target);
				break;
			case 4:
				vziiiiiiipAttack(target);
				break;
			default:
				meleeAttack(target);
		}
	}
}
