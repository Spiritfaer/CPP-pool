#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character {
private:
	std::string	_name;
	size_t		_ap;
	AWeapon		*_weapon;

	Character();
	Character(Character const &);
	Character &operator=(Character const &);
public:
	Character(std::string const & name);
//	[...]
	~Character();
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string const &getName() const;
	AWeapon const &getWeapon() const;
	bool isUnarmed() const;
	bool loseAP(size_t);
	size_t getAP() const;
};

std::ostream &operator<<(std::ostream &os, Character const&);

#endif
