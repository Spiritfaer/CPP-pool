#include "Enemy.hpp"
#include "main.hpp"

Enemy::Enemy() : Object(1, 1, ENEMY_CHAR) {}
Enemy::Enemy(int x) : Object(1, x, ENEMY_CHAR) {}
Enemy::Enemy(Enemy const &other) { this->_pos = other._pos; this->_body = other._body; }
Enemy::~Enemy() {}

Ball*	Enemy::attack() const
{
	if (_pos._y < (PLAY_WINDOW_H / 2))
		return new Ball(_pos._y + 1, _pos._x);
	else
		return nullptr;
}
