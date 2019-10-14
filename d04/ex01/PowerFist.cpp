#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}
PowerFist::~PowerFist() {}
PowerFist::PowerFist(std::string const &name, int apcost, int damage)
		: AWeapon(name, apcost, damage) {}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
