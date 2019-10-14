#include <iostream>
#include "Character.hpp"

Character::Character() {}
Character::~Character() {}

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(nullptr) {}

void Character::recoverAP() {
	if (_ap >= 40)
		return;
	if (_ap + 10 >= 40)
		_ap = 40;
	else
		_ap += 10;
}

void Character::equip(AWeapon *weapon) {
	_weapon = weapon;
}

void Character::attack(Enemy *enemy) {

	if (!loseAP(_weapon->getAPCost()))
		return;
	std::cout
		<< getName()
		<< " attacks "
		<< enemy->getType()
		<< " with a "
		<< _weapon->getName()
		<< std::endl;
	if (_weapon)
		_weapon->attack();
	enemy->takeDamage(_weapon->getDamage());
	if (!enemy->getHP())
		delete enemy;
}

bool Character::loseAP(size_t lose) {
	if (lose > _ap)
		return false;
	_ap -= lose;
	return true;
}

std::string const& Character::getName() const { return this->_name; }
size_t Character::getAP() const { return this->_ap; }
bool Character::isUnarmed() const { return (_weapon != nullptr); }
AWeapon const& Character::getWeapon() const { return *(this->_weapon); }

std::ostream &operator<<(std::ostream &os, Character const& ch) {
	std::string weapon = ch.isUnarmed() ? "wields a " + ch.getWeapon().getName() : "is unarmed";
	os << ch.getName() << " has " << ch.getAP() << " AP and "
	<<  weapon << std::endl;
	return os;
}