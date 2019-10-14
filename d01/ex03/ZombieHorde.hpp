#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {
public:

	Zombie	*horde_;
	size_t	size_;

	ZombieHorde(size_t const n = 10);
	~ZombieHorde();

	void announce() const;
	std::string	&randomChump();
};

#endif
