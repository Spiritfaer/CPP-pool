#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const &name, std::string const &title)
	: _name(name), _title(title) {
	std::cout
		<< name
		<< ", "
		<< title
		<< ", is born"
		<< std::endl;
}

Sorcerer::Sorcerer() {
	std::cout << "You can't call me!" << std::endl;
}

Sorcerer::~Sorcerer() {
	std::cout
		<< _name
		<< ", "
		<< _title
		<< ", is dead. Consequences will never be the same !"
		<< std::endl;
}

std::string
Sorcerer::introduce() const {
	std::string buff;
	buff +=
		+ "I am "
		+ _name
		+ ", "
		+ _title
		+ ", and I like ponies !\n";
	return buff;
}

void Sorcerer::polymorph(Victim const &victim) const {
	victim.getPolymorphed();
}

std::ostream& operator<<(std::ostream &os, Sorcerer const &m) {
	os << m.introduce();
	return os;
}
