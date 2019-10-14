// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 21:25:48 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 21:25:49 by istalevs         ###   ########.fr       //
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

ScavTrap::ScavTrap(std::string const & name) : _name(name) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_typeBot = "Scav";
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

unsigned int ScavTrap::getHitPoints() const { return this->_hitPoints; }
unsigned int ScavTrap::getMaxHitPoints() const { return this->_maxHitPoints; }
unsigned int ScavTrap::getEnergyPoints() const { return this->_energyPoints; }
unsigned int ScavTrap::getMaxEnergyPoints() const { return this->_maxEnergyPoints; }
unsigned int ScavTrap::getLevel() const { return this->_level; }
std::string ScavTrap::getName() const { return this->_name; }
std::string ScavTrap::getType() const { return this->_typeBot; }
unsigned int ScavTrap::getMeleeAttackDamage() const { return this->_meleeAttackDamage; }
unsigned int ScavTrap::getRangedAttackDamage() const { return this->_rangedAttackDamage; }
unsigned int ScavTrap::getArmorDamageReduction() const { return this->_armorDamageReduction; }
int ScavTrap::getRandom() const { return this->_random; }
int ScavTrap::getOldRandom() const { return this->_oldRandom; }

void ScavTrap::rangedAttack(std::string const &target) {
	std::cout << this->_typeBot << " " << this->_name << " attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " attacks " << target << " at melee, causing "
			  << this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints < amount - this->_armorDamageReduction) {
		this->_hitPoints = 0;
		std::cout << "F***! I got " << amount << " damage, and now I have " << this->_hitPoints << " hit points" << std::endl;
	}
	else {
		this->_hitPoints -= amount - this->_armorDamageReduction;
		std::cout << "Master! I got " << amount << " damage, and now I have " << this->_hitPoints << " hit points" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
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

void ScavTrap::beWait() {
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

bool ScavTrap::beFatigue() {
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

void ScavTrap::oneAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " use one attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 1 << " points of damage!" << std::endl;
}
void ScavTrap::tripleAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " use triple attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 3 << " points of damage!" << std::endl;
}
void ScavTrap::megaAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " use mega attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage  * 5.5 << " points of damage!" << std::endl;
}
void ScavTrap::godlikeAttack(std::string const &target) {
	std::cout << this->_typeBot << " " << this->_name << " use godlike attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 10 << " points of damage!" << std::endl;
}
void ScavTrap::vziiiiiiipAttack(std::string const &target) {
	std::cout << this->_typeBot << " " << this->_name << " use vziiiiiiip attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 0.5 << " points of damage!" << std::endl;
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
					"Make Eugene shave his beard!" };
	std::cout << "I order you to " << order[rundom]	<< " right now! Good luck, " << target <<  "... Muahahaha :D" << std::endl;
}
