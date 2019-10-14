#include "ZombieEvent.hpp"
#include <iostream>

ZombieEvent::ZombieEvent(std::string const &type) {
	type_ = type;
}
ZombieEvent::~ZombieEvent() {}

void
ZombieEvent::setZombieType(std::string const &type) {
	type_ = type;
}
Zombie*
ZombieEvent::newZombie(std::string const &name) {
	return new Zombie(name, type_);
}
void
ZombieEvent::randomChump() {
	static size_t cof = 1;
	static std::string preName[] = { "Dim Dim", "Genaaaaa", "DenCHik", "Igor", "Voooodim" };
	std::srand(unsigned(std::time(nullptr)));

	Zombie tmp(preName[(std::rand() % ++cof) % 5], type_);
	tmp.announce();
}
