#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	sayBorn();
}

SuperMutant::~SuperMutant() {
	sayDie();
}

SuperMutant::SuperMutant(size_t hp, std::string const &type) : Enemy(hp, type) {
	sayBorn();
}

void SuperMutant::sayBorn() const {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

void SuperMutant::sayDie() const {
	std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int damage) {
	damage = damage > 3 ? damage - 3 : 0;
	if (!getHP() || !damage)
		return;
	if (getHP() > damage)
		setHP(getHP() - damage);
	else
		setHP(0);
}
