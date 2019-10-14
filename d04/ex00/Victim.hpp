#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>

class Victim {
public:
	std::string		_name;

	Victim(std::string const &name);
	virtual ~Victim();

	std::string introduce(void) const;
	virtual void getPolymorphed() const;
	virtual void sayBorn() const;
	virtual void sayDie() const;

private:
	Victim();
	Victim(Victim const &);
	Victim &operator=(Victim const&);

};

std::ostream &operator<<(std::ostream &os, Victim const &m);


#endif
