#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:

	Weapon(std::string const &type_weapon);

	std::string	const &getType() const;
	void	setType(std::string const& type);
private:
	std::string	type_;
};

#endif
