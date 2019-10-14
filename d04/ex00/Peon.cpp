#include <iostream>
#include "Peon.hpp"

Peon::Peon(std::string const &name) : Victim(name) {
	sayBorn();
}

Peon::~Peon() {
	sayDie();
}

void Peon::sayBorn() const {
	std::cout << "Zog zog." << std::endl;
}

void Peon::sayDie() const {
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const {
	std::cout
		<< _name
		<< " has been turned into a pink pony !"
		<< std::endl;
}
