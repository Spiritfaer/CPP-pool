#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
private:
	PowerFist(PowerFist const&);
	PowerFist &operator=(PowerFist const&);
public:
	PowerFist();
	PowerFist(std::string const & name, int apcost, int damage);
	~PowerFist();

	void attack() const;
};

#endif
