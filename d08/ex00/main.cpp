#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main()
{
	std::vector<int> DemoVector;
	std::vector<int> Empty;

	DemoVector.push_back(55);
	DemoVector.push_back(-755);
	DemoVector.push_back(0);
	DemoVector.push_back(78);
	DemoVector.push_back(13);
	DemoVector.push_back(2);
	DemoVector.push_back(256);

	try {
		easyfind(DemoVector, 13);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	try {
		easyfind(DemoVector, 3);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	try {
		easyfind(Empty, -755);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
