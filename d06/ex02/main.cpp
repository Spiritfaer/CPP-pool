#include <iostream>
//#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	static int cof = 1;
	std::srand(std::time(nullptr));
	switch ((rand() * ++cof) % 3) {
		case 1 :
			return new A;
		case 2 :
			return new B;
		default:
			return new C;
	}
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer is - A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Pointer is - B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Pointer is - C" << std::endl;
}

void identify_from_reference(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference is - A" << std::endl;
	} catch (std::exception &ex) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference is - B" << std::endl;
	} catch (std::exception &ex) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference is - C" << std::endl;
	} catch (std::exception &ex) {}

}

int main()
{
	Base *one = generate();
	Base *two = generate();
	Base *three = generate();

	identify_from_pointer(one);
	identify_from_pointer(two);
	identify_from_pointer(three);

	identify_from_reference(*one);
	identify_from_reference(*two);
	identify_from_reference(*three);

	return 0;
}
