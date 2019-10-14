#include <sstream>
#include "Brain.hpp"

std::string Brain::identify() const {
	std::ostringstream oss;
	oss << this;
	return oss.str();
}
