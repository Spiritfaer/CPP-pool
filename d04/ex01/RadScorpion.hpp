#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy {
private:
	RadScorpion(RadScorpion const &);
	RadScorpion &operator=(RadScorpion const &);
public:
	RadScorpion();
	RadScorpion(size_t hp, std::string const & type);
	virtual ~RadScorpion();

	void sayBorn(void) const;
	void sayDie(void) const;
};


#endif
