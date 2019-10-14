#ifndef AWEAPON_HPP
#define AWEAPON_HPP
#include <string>


class AWeapon {
private:
	std::string	_name;
	size_t		_APcost;
	size_t		_damage;

	AWeapon(AWeapon const &);
	AWeapon& operator=(AWeapon const &);
public:
	AWeapon();
	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon();

	std::string const& getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
};


#endif
