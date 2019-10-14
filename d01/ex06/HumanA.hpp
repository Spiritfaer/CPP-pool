#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	Weapon		const &weapon_;
	std::string	name_;

	HumanA(std::string const &name, Weapon const &weapon);
	void attack() const;
};

#endif
