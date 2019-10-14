#include <iostream>

int		main(void)
{
	std::string *reference = new std::string("HI THIS IS BRAIN");
	std::string &link = *reference;
	std::string *pointer = reference;
	std::cout << "Link: " << link << std::endl;
	std::cout << "Pointer: " << *pointer << std::endl;

	delete reference;
	return 0;
}
