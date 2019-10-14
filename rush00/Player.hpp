#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Object.hpp"
#include "Ball.hpp"

class Player : public Object
{
public:
	int		_hp;
	int		_score;

	Player();
	Player(int, int);
	Player(Player const &);
	Player&	operator=(Player const &);
	virtual ~Player();
	void	damageHP();
	void	upScore();
	Ball 	*attack() const;
};

#endif
