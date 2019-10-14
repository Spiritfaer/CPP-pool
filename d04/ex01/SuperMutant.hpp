#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy {
private:
	SuperMutant(SuperMutant const &);
	SuperMutant&operator=(SuperMutant const&);
public:
	SuperMutant();
	SuperMutant(size_t hp, std::string const &type);
	~SuperMutant();

	void takeDamage(int);

	void sayBorn(void) const;
	void sayDie(void) const;
};


#endif
