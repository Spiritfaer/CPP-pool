#ifndef POEN_HPP
#define POEN_HPP


#include "Victim.hpp"

class Peon : public Victim {
public:
	Peon(std::string const &name);
	~Peon();

	void sayBorn() const;
	void sayDie() const;
	void getPolymorphed() const;

private:
	Peon();
	Peon(Peon const &);
	Peon	&operator=(Peon const &);
};

std::ostream &operator<<(std::ostream &os, Victim const &m);


#endif
