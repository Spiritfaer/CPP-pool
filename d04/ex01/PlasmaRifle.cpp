#include <iostream>
#include "PlasmaRifle.hpp"


PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}
PlasmaRifle::~PlasmaRifle() {}
PlasmaRifle::PlasmaRifle(std::string const &name, int apcost, int damage)
	: AWeapon(name, apcost, damage) {}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
