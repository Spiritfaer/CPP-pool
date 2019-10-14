#include "ZombieHorde.hpp"
#include <iostream>

ZombieHorde::ZombieHorde(const size_t n) : size_(n) {
	horde_ = new Zombie[n];
	for (size_t i = 0; i < n; ++i)
	{
		horde_[i].setName(randomChump());
		horde_[i].setType("horde");
	}
}

ZombieHorde::~ZombieHorde() {
	delete [] horde_;
}

std::string	&
ZombieHorde::randomChump() {
	static size_t cof = 1;
	static std::string preName[] = { "Dim Dim", "Genaaaaa", "DenCHik", "Igor", "Voooodim" };
	std::srand(unsigned(std::time(nullptr)));
	return preName[(std::rand() % ++cof) % 5];
}

void ZombieHorde::announce() const {
	std::cout << "HORDE ARE HERE!" << std::endl;
	for (size_t i = 0; i < size_; ++i) {
		horde_[i].announce();
	}
}
