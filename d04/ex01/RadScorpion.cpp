#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	sayBorn();
}

RadScorpion::~RadScorpion() {
	sayDie();
}

RadScorpion::RadScorpion(size_t hp, std::string const &type) : Enemy(hp, type) {
	sayBorn();
}

void RadScorpion::sayBorn() const {
	std::cout << "* click click click *" << std::endl;
}

void RadScorpion::sayDie() const {
	std::cout << "* SPROTCH *" << std::endl;
}
