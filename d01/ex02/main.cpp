#include "ZombieEvent.hpp"

int		main(void)
{
	ZombieEvent testRandomName;

	testRandomName.setZombieType("sleepy");
	testRandomName.randomChump();
	testRandomName.randomChump();
	testRandomName.randomChump();

	testRandomName.setZombieType("goodness");
	testRandomName.randomChump();
	testRandomName.randomChump();
	testRandomName.randomChump();
	testRandomName.randomChump();

	testRandomName.setZombieType("Fucker");
	Zombie *ptr = testRandomName.newZombie("Stick");
	ptr->announce();
	delete ptr;

	return 0;
}
