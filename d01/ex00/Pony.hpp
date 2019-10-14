#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony
{
public:

	Pony();
	Pony(std::string const &name);
	~Pony();

	void				setName(std::string const &name);
	std::string const	&getName(void) const;
	void				getPain(void) const;

private:
	void				sayHello(void) const;

	std::string name_;
};
#endif
