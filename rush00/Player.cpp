#include "Player.hpp"
#include "main.hpp"

Player::Player() : Object(1, 1, PLAYER_CHAR) {
	_hp = 5;
	_score = 0;
}

Player::Player(int h, int w) : Object(h - 2, w / 2, PLAYER_CHAR) {
	_hp = 5;
	_score = 0;
}

Player::Player(Player const & src) : Object(src) {
	this->_hp = src._hp;
	this->_score = src._score;
}

Player &	Player::operator=(Player const & src) {
	if (this == &src)
		return *this;
	this->_hp = src._hp;
	this->_score = src._score;
	this->_pos = src._pos;
	this->_body = src._body;
	return *this;
}

Player::~Player() {}
Ball *	Player::attack() const { return new Ball(_pos._y - 1, _pos._x); }
void	Player::damageHP() { if (_hp != 0) _hp--; }
void	Player::upScore() { _score++; }
