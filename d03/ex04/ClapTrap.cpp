// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 23:10:06 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 23:10:13 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

ClapTrap::ClapTrap () {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 0;
	this->_maxHitPoints = 100;
	this->_energyPoints = 0;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_typeBot = "ClapTrap";
	this->_name = "No-name";
	this->_meleeAttackDamage = 0;
	this->_rangedAttackDamage = 0;
	this->_armorDamageReduction = 0;
	std::cout << this->_typeBot << " Constructor called" <<std::endl;
}

ClapTrap::ClapTrap( std::string const & name ) {
	this->_random = 0;
	this->_oldRandom = 0;
	this->_hitPoints = 0;
	this->_maxHitPoints = 100;
	this->_energyPoints = 0;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_typeBot = "ClapTrap";
	this->_name = name;
	this->_meleeAttackDamage = 0;
	this->_rangedAttackDamage = 0;
	this->_armorDamageReduction = 0;
	std::cout << this->_typeBot << " Constructor called" <<std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {
	std::cout << this->_typeBot << "Copy Constructor called" <<std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor " << this->_typeBot << " called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &src) {
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

unsigned int ClapTrap::getHitPoints() const { return this->_hitPoints; }
unsigned int ClapTrap::getMaxHitPoints() const { return this->_maxHitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return this->_energyPoints; }
unsigned int ClapTrap::getMaxEnergyPoints() const { return this->_maxEnergyPoints; }
unsigned int ClapTrap::getLevel() const { return this->_level; }
std::string ClapTrap::getName() const { return this->_name; }
std::string ClapTrap::getType() const { return this->_typeBot; }
unsigned int ClapTrap::getMeleeAttackDamage() const { return this->_meleeAttackDamage; }
unsigned int ClapTrap::getRangedAttackDamage() const { return this->_rangedAttackDamage; }
unsigned int ClapTrap::getArmorDamageReduction() const { return this->_armorDamageReduction; }
int ClapTrap::getRandom() const { return this->_random; }
int ClapTrap::getOldRandom() const { return this->_oldRandom; }

void ClapTrap::rangedAttack(std::string const &target) {
	std::cout << this->_typeBot << " " << this->_name << " attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " attacks " << target << " at melee, causing "
			  << this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints < amount - this->_armorDamageReduction) {
		this->_hitPoints = 0;
		std::cout << "F***! I got " << amount << " damage, and now I have " << this->_hitPoints << " hit points" << std::endl;
	}
	else {
		this->_hitPoints -= amount - this->_armorDamageReduction;
		std::cout << "Master! I got " << amount << " damage, and now I have " << this->_hitPoints << " hit points" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
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

void ClapTrap::beWait() {
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

bool ClapTrap::beFatigue() {
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

void ClapTrap::oneAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " use one attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 1 << " points of damage!" << std::endl;
}
void ClapTrap::tripleAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " use triple attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 3 << " points of damage!" << std::endl;
}
void ClapTrap::megaAttack(std::string const & target) {
	std::cout << this->_typeBot << " " << this->_name << " use mega attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage  * 5.5 << " points of damage!" << std::endl;
}
void ClapTrap::godlikeAttack(std::string const &target) {
	std::cout << this->_typeBot << " " << this->_name << " use godlike attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 10 << " points of damage!" << std::endl;
}
void ClapTrap::vziiiiiiipAttack(std::string const &target) {
	std::cout << this->_typeBot << " " << this->_name << " use vziiiiiiip attacks " << target << " at range, causing "
			  << this->_rangedAttackDamage * 0.5 << " points of damage!" << std::endl;
}
