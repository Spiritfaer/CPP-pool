#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Ball.hpp"
#include "Object.hpp"

class Enemy : public Object
{
public:
	Enemy();
	Enemy(int x);
	Enemy(Enemy const & other);
	virtual ~Enemy();
	Ball *	attack() const;
private:
	Enemy &	operator=(Enemy const & src);

};

#endif
