#include <iostream>
#include "Victim.hpp"

Victim::Victim(std::string const &name) : _name(name){
	sayBorn();
}

Victim::Victim() {
	std::cout << "You can't call me!" << std::endl;
}

Victim::~Victim() {
	sayDie();
}
std::string
Victim::introduce() const {
	std::string buff;
	buff +=
		+ "I'm "
		+ _name
		+ " and I like otters !\n";
	return buff;
}

void Victim::getPolymorphed() const {
	std::cout
		<< _name
		<< " has been turned into a cute little sheep !"
		<< std::endl;
}

void Victim::sayBorn() const {
	std::cout
		<< "Some random victim called "
		<< _name
		<< " just popped !"
		<< std::endl;
}

void Victim::sayDie() const {
	std::cout
		<< "Victim "
		<< _name
		<< " just died for no apparent reason !"
		<< std::endl;
}

std::ostream& operator<<(std::ostream &os, Victim const &m) {
	os << m.introduce();
	return os;
}
