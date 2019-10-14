#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	Weapon		const *weapon_;
	std::string	name_;

	HumanB(std::string const &name);
	void attack() const;
	void setWeapon(Weapon const &weapon);
};

#endif
