#include <iostream>
#include "Replacing.hpp"


int		main(int argc, char **argv)
{
	if (argc < 3) {
		std::cout << "NOT ENOUGH ARGUMENTS" << std::endl;
		return 0;
	}

	Replacing repl(argv[1]);
	repl.replace(argv[2], argv[3]);
	std::cout << "FILE WAS MODIFYING" << std::endl;

	return 0;
}
