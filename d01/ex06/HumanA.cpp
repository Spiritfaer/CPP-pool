#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon const &weapon) : weapon_(weapon), name_(name) {}

void
HumanA::attack() const {
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}
