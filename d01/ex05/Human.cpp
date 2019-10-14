#include <sstream>
#include "Human.hpp"

Brain const &Human::getBrain() const {
	return brain_;
}

std::string Human::identify() {
	std::ostringstream oss;
	oss << &this->brain_;
	return oss.str();
}
