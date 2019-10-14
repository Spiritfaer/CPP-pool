#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const &name) : name_(name) {}

void
HumanB::setWeapon(Weapon const &weapon) {
	weapon_ = &weapon;
}

void
HumanB::attack() const {
	std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}
