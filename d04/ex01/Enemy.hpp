#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy
{
private:
	size_t		_hp;
	std::string	_type;

	Enemy();
	Enemy(Enemy const &);
	Enemy &operator=(Enemy const &);
public:
	Enemy(int hp, std::string const & type);
	virtual ~Enemy();
	std::string const &getType() const;
	int getHP() const;
	virtual void takeDamage(int);

	void setHP(int);
	virtual void sayBorn(void) const = 0;
	virtual void sayDie(void) const = 0;
};


#endif
