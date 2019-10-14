#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <string>
#include "Victim.hpp"

class Sorcerer {
public:
	Sorcerer(std::string const &name, std::string const &title);
	~Sorcerer();

	std::string introduce(void) const;
	void polymorph(Victim const &) const;

private:
	Sorcerer();
	Sorcerer(Sorcerer const &);
	Sorcerer &operator=(Sorcerer const&);


	std::string		_name;
	std::string		_title;
};

std::ostream &operator<<(std::ostream &os, Sorcerer const &m);

#endif
