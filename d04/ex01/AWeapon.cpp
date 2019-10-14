#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon() : _name("stick"), _APcost(1), _damage(1) {}
AWeapon::~AWeapon() {}

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
	: _name(name), _APcost(apcost), _damage(damage) {}

std::string const& AWeapon::getName() const { return this->_name; }
int AWeapon::getAPCost() const { return this->_APcost; }
int AWeapon::getDamage() const { return this->_damage; }