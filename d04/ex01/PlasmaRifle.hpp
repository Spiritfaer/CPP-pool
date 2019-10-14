#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP
#include "AWeapon.hpp"


class PlasmaRifle : public AWeapon {
private:
	PlasmaRifle(PlasmaRifle const&);
	PlasmaRifle &operator=(PlasmaRifle const&);
public:
	PlasmaRifle();
	PlasmaRifle(std::string const & name, int apcost, int damage);
	~PlasmaRifle();

	void attack() const;
};


#endif
