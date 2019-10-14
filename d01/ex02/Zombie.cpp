#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &name, const std::string &type) {
	name_ = name;
	type_ = type;
}

void
Zombie::announce() const {
	std::cout << "<" << name_ <<" ("<< type_ <<")> Braiiiiiiinnnssss..." << std::endl;
}

std::string const& Zombie::getName() const { return name_; }
std::string const& Zombie::getType() const { return type_; }

void
Zombie::setName(const std::string &name) {
	name_ = name;
}
void
Zombie::setType(const std::string &type) {
	type_ = type;
}
