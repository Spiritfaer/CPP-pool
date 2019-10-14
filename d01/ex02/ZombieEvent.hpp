#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {

public:
	std::string type_;

	ZombieEvent(std::string const &type = "no_type");
	~ZombieEvent();

	void		setZombieType(std::string const &type = "no_type");
	Zombie*		newZombie(std::string const &name);
	void		randomChump();
};

#endif
