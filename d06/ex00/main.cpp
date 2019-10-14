#include <iostream>
#include "ScalarConversion.hpp"

void	checkArguments(int argc) {
	if (argc < 2) {
		std::cout << "Not enough arguments" << std::endl;
		exit(1);
	}
}

int main(int argc, char **argv)
{
	checkArguments(argc);
    ScalarConversion convClass(argv[1]);

	convClass.infoChar();
	convClass.infoInteger();
	convClass.infoFloat();
	convClass.infoDouble();

	return 0;
}
