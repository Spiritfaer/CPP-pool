#include <ncurses.h>
#include <iostream>
#include <ctime>
#include <signal.h>
#include "World.hpp"
#include "main.hpp"


int		main()
{
	World		world;

	world.init();
	world.checkSize(&world);
	world.makeWindow();
	world.showBox();
	world.initTimer();
	world.play();
	world.end();
	return 0;
}
