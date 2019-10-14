#include <iostream>
#include "Human.hpp"

int		main( void )
{
	Human test;

	test.action("intimidatingShout", "Dimon");
	test.action("rangedAttack", "Pony");
	test.action("meleeAttack", "Gena");

	return 0;
}
