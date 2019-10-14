#include "Weapon.hpp"

Weapon::Weapon(std::string const &type_weapon) : type_(type_weapon) {}

std::string const&
Weapon::getType() const {
	return type_;
}

void
Weapon::setType(std::string const &type) {
	type_ = type;
}
