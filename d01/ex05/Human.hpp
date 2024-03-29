#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human {
public:
	Brain const brain_;

	Brain const &getBrain() const;
	std::string identify();
};

#endif
