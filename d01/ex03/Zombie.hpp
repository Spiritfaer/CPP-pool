#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:

	Zombie(std::string const& name = "Dude", std::string const& type = "sleepy");

	std::string const& getName() const;
	std::string const& getType() const;

	void	setName(std::string const &name);
	void	setType(std::string const &type);

	void announce() const;

private:
	std::string	name_;
	std::string	type_;
};


#endif
